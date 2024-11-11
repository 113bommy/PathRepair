N, M = list(map(int, input().split(' ')))
MOD = int(1e9 + 7)
seeds = []
p = 2
while p*p <= M:
  while M % p == 0:
    seeds.append(p)
    M = M // p
  p += 1
if M > 1:
  seeds.append(M)
 
def comb(n, k):
  ans = 1
  for i in range(1, k + 1):
    ans = (ans * (n + 1 - i) // i)
  return ans
 
ans = 1
hogehoge = set(seeds)
for i in hogehoge:
  a_ct = seeds.count(i)
  ans = (ans * comb(a_ct + N-1, min(a_ct, N-1))) % MOD
print(ans)
