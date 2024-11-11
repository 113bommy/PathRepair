n=int(input())
a=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
i,j,p,s=n-1,n-1,True,0
while i>=0 or j>=0:
    if p:
        if i==-1: j-=1
        elif j==-1:
            s+=a[i]
            i-=1
        else:
            if a[i]<=b[j]:
                j-=1
            else:
                s+=a[i]
                i-=1
    else:
        if j==-1: i-=1
        elif i==-1:
            s-=b[j]
            j-=1
        else:
            if a[i]>=b[j]:
                i-=1
            else:
                s-=b[j]
                j-=1
    p=not p
print(s)