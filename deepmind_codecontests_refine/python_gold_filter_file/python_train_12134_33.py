n=int(input())
a=list(map(int,input().split()))
c,mxc=1,1
for i in range(n-1):
    if a[i]<a[i+1]:
        c+=1
    else:
        c=1
    mxc= max(c,mxc)
print(mxc)   