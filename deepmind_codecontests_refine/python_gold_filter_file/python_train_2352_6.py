n,m,k=map(int,input().split())
n=n-1
m=m-1
a=list(map(int,input().split()))
l_d=0
l_p=m+1
if l_p>n:
    l_d=999
else:
    found=False
    while l_p<=n:
        if a[l_p]>0 and a[l_p]<=k:
            found=True
            break
        else:
            l_d+=1
            l_p+=1
    if found==False:
        l_d=9999

r_d=0
r_p=m-1
if r_p<0:
    r_d=999
else:
    found=False
    while r_p>=0:
        if a[r_p]>0 and a[r_p]<=k:
            found=True
            break
        else:
            r_p-=1
            r_d+=1
    if found==False:
        r_d=999

print((min(r_d,l_d)+1)*10)
