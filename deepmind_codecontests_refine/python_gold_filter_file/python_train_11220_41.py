n,*a=map(int,open(0).read().split())
a.sort()
ans=1
for ai in a:
  ans*=ai
  if ans>10**18:
    print(-1)
    exit()
print(ans)