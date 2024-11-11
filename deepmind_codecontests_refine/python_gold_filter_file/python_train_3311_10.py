r,g,b,n=map(int,input().split())
l=n//min(r,g,b)
ans=0
for i in range(l+1):
  for j in range(l+1):
      if n-(i*r+j*g)>=0 and (n-(i*r+j*g))%b==0:
        ans+=1
print(ans)