N=int(input())
ans=0
for x in range(N):
  x,u=input().split()
  if u=="JPY":
    ans+=int(x)
  else:
    ans+=380000*float(x)
print(ans)