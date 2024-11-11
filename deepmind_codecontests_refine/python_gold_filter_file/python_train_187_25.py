from itertools import product
N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]
A = [0, 1]
M = -10**18
Pr = list(product(A, repeat=10))
Pr.remove((0,0,0,0,0,0,0,0,0,0))
for I in Pr:
  s = 0
  for i in range(N):
    s += P[i][sum(i*f for i, f in zip(I, F[i]))]
  M = max(M, s)
print(M)