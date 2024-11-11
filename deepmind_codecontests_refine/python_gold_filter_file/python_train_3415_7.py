n,l=map(int,input().split())
ans=(2*l+n-1)*n//2
if l-1>=0:
  ans-=l
elif l-1<=0 and abs(l-1)>=n:
  ans-=l+n-1
print(ans)