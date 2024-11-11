#!/usr/bin/env python3
# -*- coding: utf-8 -*-

query_num = int(input())

for i in range(query_num):
    k, n, a, b = map(int, input().split())
    
    if (k // b) < n or (k//b == n and k%b==0):
        print(-1)
        continue
    
    #(a-b)*x < k-b*n
    gap = a-b
    right = k-b*n
    
    turns = (right-1) // gap 
    if turns >=n:
        print(n)
    else:
        print(turns)
    
    
    
        

