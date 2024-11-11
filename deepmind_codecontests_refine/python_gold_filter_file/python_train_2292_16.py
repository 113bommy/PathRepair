# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10 ** 9)
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

H=INT()
# 1-indexedにしたいので先頭に番兵的なものを足す
A=['']+LIST()

def maxHeapify(A, i):
    l=i*2
    r=i*2+1
    if l<=H and A[l]>A[i]:
        mx=l
    else:
        mx=i
    if r<=H and A[r]>A[mx]:
        mx=r
    if mx!=i:
        A[i],A[mx]=A[mx],A[i]
        maxHeapify(A, mx)

for i in range(H//2, 0, -1):
    maxHeapify(A, i)

print(*A)

