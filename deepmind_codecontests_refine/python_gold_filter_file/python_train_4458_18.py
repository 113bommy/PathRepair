ans=0.0
n=int(input())
for i in range(n):
  a, s = input().split()
  a = float(a)
  if s=="BTC" :
    a *= 380000.0
  ans += a
print(ans)
