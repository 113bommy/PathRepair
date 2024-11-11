import sys
input = sys.stdin.readline
from itertools import accumulate

n, k = map(int, input().split())
A = tuple(map(int, input().split()))
for _ in range(k):
  C = [0]*n
  for i, a in enumerate(A):
    C[max(0, i-a)] += 1
    if i+a < n-1:
      C[i+a+1] -= 1
  A = tuple(accumulate(C))
  if min(A) == n:
    break
print(*A)