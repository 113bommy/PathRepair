r,g,b,n=map(int,input().split())
R=n//r
ans=0
for i in range(R+1):
  for j in range(((n-i*r)//g)+2):
    if 0<=n-i*r-j*g and (n-i*r-j*g)%b==0:
      ans+=1
print(ans)