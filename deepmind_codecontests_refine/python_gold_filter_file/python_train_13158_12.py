#!/usr/bin/env python3
import io
import os
import sys

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def printd(*args, **kwargs):
    #print(*args, **kwargs, file=sys.stderr)
    #print(*args, **kwargs)
    pass

def get_str():
    return input().decode().strip()

def rint():
    return map(int, input().split())

def oint():
    return int(input())

n, k = rint()

a = list(rint())

psum = [a[0]]
for i in range(1, n):
    psum.append(a[i]+psum[i-1])

ksum = [psum[k-1]]

for i in range(1, n-k+1):
    ksum.append(psum[i+k-1] - psum[i-1])

printd('a    ', a)
printd('ksum ', ksum)

maxsum = [[-1, 0] for i in range(n-k+1)]
maxsum[n-k] =[ksum[n-k], n-k]
for i in range(n-k-1, -1, -1):
    if ksum[i] >= maxsum[i+1][0]:
        maxsum[i] = [ksum[i], i]
    else:
        maxsum[i] = [maxsum[i+1][0], maxsum[i+1][1]]
printd('maxsum', maxsum)
maxsum_ = -1
ans = [0,0]
for i in range(n-k-k+1):
    sum_ = ksum[i] + maxsum[i+k][0]
    if sum_ > maxsum_:
        ans = [i, maxsum[i+k][1]]
        maxsum_ = sum_

print(ans[0]+1, ans[1]+1)
