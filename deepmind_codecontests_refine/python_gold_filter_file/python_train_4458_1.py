N = int(input())
ans =0
for i in range(N):
  a,b = input().split()
  a = float(a)
  if b=="JPY":
    ans+=a
  else:
    ans +=a*380000
print(ans)