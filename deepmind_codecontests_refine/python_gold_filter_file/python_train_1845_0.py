# -*- coding: utf-8 -*-
"""
Created on Sun Jun  3 14:17:31 2018

@author: du-wan
"""


n = int(input())
res = {}

for i in range(n): 
    vec_len = int(input()) 
    seq = [int(i) for i in input().split()]
    sum_seq = sum(seq)
    for j in range(len(seq)):
        diff = sum_seq-seq[j]
        if diff not in res: 
            res[diff] = (i+1, j+1)
        if diff in res and res[diff][0] != i+1:  #solution found and not from same sequence
            print("YES")
            print(res[diff][0], res[diff][1])
            print(i+1, j+1)
            exit(0)
print ("NO")
    