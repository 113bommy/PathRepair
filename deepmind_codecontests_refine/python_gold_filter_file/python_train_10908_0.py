N, K = map(int, input().split())
mod = 10**9+7
kosu_table = [0]*(K+1)
i = K
while i > 0:
  kosu_table[i] = pow(K//i, N, mod)
  j = 2
  while i*j <= K:
    kosu_table[i] -= kosu_table[i*j]
    j += 1
  i -= 1
print(sum([i*kosu_table[i] for i in range(1, K+1)])%mod)
