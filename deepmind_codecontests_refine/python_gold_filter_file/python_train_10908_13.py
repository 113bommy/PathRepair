n, k = map(int, input().split())
mod = MOD = 10**9 + 7

G = [0] + [pow(k//i, n, mod) for i in range(1,k+1)]
for i in range(k, 0, -1):
  for j in range(2, k//i+1):
    G[i] -= G[j*i]

print(sum([i*f for i,f in enumerate(G)]) % mod)