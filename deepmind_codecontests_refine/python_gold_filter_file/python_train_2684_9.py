mod = 998244353

n, m, k = map(int, input().split())
count = 0

comb = 1
for i in range(k + 1):
  tmp = comb * m * pow(m-1, n-i-1, mod) % mod
  count = (count + tmp) % mod
  comb = comb * (n - i - 1) * pow(i+1, mod-2, mod) % mod
print(count)