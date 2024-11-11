# -*- coding: utf-8 -*-
import sys

N,K,*A = map(int, sys.stdin.buffer.read().split())

for _ in range(K):
  Anext = [0 for _ in range(N+1)]
  for i in range(N):
    Anext[max(0,i-A[i])] += 1
    Anext[min(N,i+A[i]+1)] -= 1
  cumsum = 0
  for i in range(N):
    cumsum += Anext[i]
    A[i] = cumsum
  if min(A)==N:
    break

print(' '.join([str(a) for a in A]))