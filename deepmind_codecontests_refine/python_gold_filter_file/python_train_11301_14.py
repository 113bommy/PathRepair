l,r,a,b,k=map(int,input().split())
if a>l:l=a
if b<r:r=b
print(max(r-l+1-(l<=k<=r),0))