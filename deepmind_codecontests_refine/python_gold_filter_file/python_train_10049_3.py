n,k=map(int,input().split())
if k==0 or n==1:
  print(0)
elif k>=n//2:
  print(((n-1)*n)//2)
else:
  ans=0
  
  for i in range(1,n+1):
   if i<=k:
    ans+=n-i
   elif i<=n-k:ans+=k
 
  for j  in range(k-1,-1,-1):
     ans+=j
  print(ans)
