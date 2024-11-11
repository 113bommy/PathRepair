import math
str=input("")
n,H=int(str.split(' ')[0]),int(str.split(' ')[1])
maxh=0
if H+H*H>=2*n:
    maxh=int(math.sqrt(2*n))-1
    while maxh*(maxh+1)<=2*n:
        maxh+=1
    maxh-=1
    if maxh*(maxh+1)==2*n:
        ans=maxh
    else :
        ans=maxh+1
else:
    n=int(n+H*(H-1)/2)
    maxh=int(math.sqrt(n))
    if maxh*maxh==n:
        ans=2*maxh-H
    elif n-maxh*maxh>maxh:
        ans=2*maxh-H+2
    else :
        ans=2*maxh-H+1
print(ans)