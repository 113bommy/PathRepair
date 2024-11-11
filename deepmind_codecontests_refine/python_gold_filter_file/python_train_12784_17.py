ans=0
n,x=map(int,input().split())
l=list(map(int,input().split()))
d=0
for i in l:
  d+=i
  if d<=x:ans+=1
print(ans+1)
