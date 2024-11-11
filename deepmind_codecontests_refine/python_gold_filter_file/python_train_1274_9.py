t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=0
    t=a[0]
    temp=a[0]
    for i in range(1,n):
        if t>0 and a[i]>0:
            temp=max(temp,a[i])
        elif t>0 and a[i]<0:
            s+=temp
            temp=a[i]
            t=a[i]
        elif t<0 and a[i]<0:
            temp=max(a[i],temp)
        elif t<0 and a[i]>0:
            s+=temp
            temp=a[i]
            t=a[i]
    print(s+temp)