k,s=map(int,input().split())
ans=0
for a in range(k+1):
  for b in range(k+1):
    if 0<=(s-a-b)<=k:
      ans+=1
print(ans)