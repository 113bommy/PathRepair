N=int(input())
ans=0
for i in range(N):
  x,u=input().split()
  if u=="JPY":
    ans+=float(x)
  else:
    ans+=(float(x)*380000)
print(ans)