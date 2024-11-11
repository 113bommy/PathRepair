# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline 

n = int(input())
a = [int(i) for i in readline().split()]
b = [int(i) for i in readline().split()]
pb = [(bi,i) for i,bi in enumerate(b)]

sa = sorted(a)
sb = sorted(b)
pb.sort()

na = [a[i] for bi,i in pb]


ok = 1
for i,j in zip(sa,sb):
    if i > j: ok = 0

for i,j in zip(sa[1:],sb):
    if i <= j: break
else:
    #sa => na が巡回置換か？
    d = {ai:i for i,ai in enumerate(sa)}
    ra = [d[ai] for ai in na]
    
    #print(ra,ok)    
    now = 0
    for i in range(n-1):
        now = ra[now]
        #print(now)
        if now == 0:
            break
    else: ok = 0    


    

#print(a,b,sa,sb,na)

if ok: print("Yes")    
else: print("No")
    
    
    
    
    
    