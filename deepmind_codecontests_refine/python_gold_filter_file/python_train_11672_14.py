n,m,k,l=map(int,input().split())
if k+l>n:ans=-1
if (l+k)%m==0:ans=(l+k)//m
else:ans=(k+l)//m+1
if ans*m>n:ans=-1
print(ans)
