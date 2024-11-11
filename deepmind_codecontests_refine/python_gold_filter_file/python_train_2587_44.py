k, s= map(int,input().split())
ans=0
for y in range(k+1):
  for z in range(k+1):
    if 0<=s-y-z<=k:
      ans+=1
print(ans)