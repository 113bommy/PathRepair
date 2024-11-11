l,r=map(int,input().split())
n=r-l if r-l < 2019 else 2019
ans=(r*l)%2019
for i in range(l, l+n+1):
  for j in range(i+1, l+n+1):
    ans=min(ans, (i*j)%2019)
print(ans)