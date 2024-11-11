x, y, z=map(int, input().split())
ans=y//z-x//z
if x%z==0:
  ans+=1
print(ans)