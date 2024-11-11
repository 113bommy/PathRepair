h,w=map(int,input().split())
l=["."*(w+2)]
for i in range(h):
  l+=["."+input()+"."]
l+=["."*(w+2)]
ans=0
for i in range(1,h+1):
  for j in range(1,w+1):
    if l[i][j]==".":
      continue
    if l[i+1][j]=="#" or l[i-1][j]=="#" or l[i][j+1]=="#" or l[i][j-1]=="#":
      continue
    ans=1
print("YNeos"[ans::2])
