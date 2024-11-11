N, S = map(int, input().split())
A = list(map(int, input().split()))
mod = 998244353
L = [0 for _ in range(S+1)]
L[0] = 1
F = {0}
for i in range(N):
  X = [[i, L[i]] for i in F]
  for j in F:
    L[j] *= 2
    L[j] %= mod
  for j in X:
    if A[i] + j[0] <= S:
      L[A[i]+j[0]] += j[1]
      L[A[i]+j[0]] %= mod
      F.add(A[i]+j[0])
print(L[S])
