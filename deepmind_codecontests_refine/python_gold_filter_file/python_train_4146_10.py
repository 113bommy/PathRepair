# -*- coding: utf-8 -*-
import collections

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
c=collections.Counter(A)

pairCounter=0

beki=29
nibeki=2**beki

for i in range(N):
  target = A[i]
  if c[target] < 1:
    continue
  c[target]-= 1

  while (nibeki > target):
    beki-=1
    nibeki=2**beki

  pair = nibeki * 2 - target
  if pair in c.keys() and c[pair] > 0:
    c[pair]-= 1
    pairCounter+=1

print(pairCounter)