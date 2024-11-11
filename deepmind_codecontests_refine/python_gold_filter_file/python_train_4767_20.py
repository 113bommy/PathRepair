#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

k,q = map(int,input().split())
D =list(map(int,input().split()))
for _ in range(q):
  n,x,m = map(int,input().split())
  DD = [(d-1+m)%m+1 for d in D]
  tmp = x; s = (n-1) // k
  for i, di in enumerate(DD):
    tmp += di*(s + int((n-1)%k > i))
  print(n-1-(tmp//m-x//m))