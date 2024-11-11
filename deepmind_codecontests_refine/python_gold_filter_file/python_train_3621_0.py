# -*- coding: utf-8 -*-
"""
Created on Sun Mar 22 13:54:24 2020

@author: naoki
"""
import sys
#f = open("C:/Users/naoki/Desktop/Atcoder/input.txt")
N = int(input())
a = list(map(lambda x:int(x)-1,list(input())))
   
all_odd = 0
kai = [0] * N

if (0 not in a) and (1 not in a):
    print(0)
    sys.exit()
if (1 not in a) and (2 not in a):
    print(0)
    sys.exit()
if (0 not in a) and (2 not in a):
    print(0)
    sys.exit()
    
for k in range(1,N):
    count = 0
    p = k
    for _ in range(N):
        if p % 2 == 1:
            kai[k] = kai[k-1] + count
            break
        p = p/2
        count += 1

all_num = 0
for k in range(N):
    if kai[-1] == kai[k] + kai[N-1-k] and a[k] == 1:
        all_num += 1

if all_num % 2 == 1:
    print(1)
elif 1 in a:
    print(0)
else:
    for i in range(N):
        a[i] = a[i]/2
    for k in range(N):
        if kai[-1] <= kai[k] + kai[N-1-k] and a[k] == 1:
            all_num += 1
    if all_num % 2 == 1:
        print(2)
    else:
        print(0)