n,m=map(int,input().split())
num=[0]*n
for i in range(m):
  a,b=map(int,input().split())
  a-=1;b-=1
  num[a]+=1;num[b]+=1
flag=0
for i in num:
  if i%2==1:
    flag=1
    break
if bool(flag):print("NO")
else:print("YES")
