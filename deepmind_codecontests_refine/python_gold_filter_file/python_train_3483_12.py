MOD = 1000000007

t, k = map(int,input().split())

ls = [0] + [1]*100000
ls[k] = 2

for i in range(k+1,100001):
  ls[i] = (ls[i-k] + ls[i-1]) % MOD

for i in range(1,100001):
  ls[i] = (ls[i]+ls[i-1]) % MOD

for _ in range(t):
  a, b = map(int,input().split())
  print((ls[b]-ls[a-1])%MOD)
