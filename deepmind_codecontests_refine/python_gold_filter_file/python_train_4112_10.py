n,s=int(input()),0
for b in range(10,-1,-1):
    if n >= 10**b:
        s += (b+1)*(n-10**b+1)
        n = 10**b - 1
print(s)
