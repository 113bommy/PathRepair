N=int(input())
p=list(input().split())
ans=0
for i in range(N):
  if i+1 !=int(p[i]):
    ans+=1
if ans==0 or ans==2:
  print("YES")
else:
  print("NO")