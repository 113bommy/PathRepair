r,g,b,n=map(int,input().split())
ans=0
for i in range(n//r+1):
  for j in range((n-r*i)//g+1):
    if (n-i*r-g*j)%b==0:ans+=1
print(ans)
