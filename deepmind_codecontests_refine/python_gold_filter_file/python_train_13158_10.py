# cook your dish here
n,k=list(map(int,input().split()))
a=[0]+list(map(int,input().split()))
if n==2*k:
    print(1,k+1)
else:
    s=[a[0]]
    for i in range(1,n+1):
        s.append(s[-1]+a[i])
    b=[]
    m=0
    for i in range(n,-1,-1):
        if i>n-k+1:
            b.append([-1,0])
        else:
            x=s[i+k-1]-s[i]+a[i]
            if x>=m:
                b.append([i,x])
                m=x
            else:
                b.append(b[-1])
    b=b[::-1]
    m,x,y=0,0,0
    for i in range(1,n-2*k+2):
        t=s[i+k-1]-s[i]+a[i]
        if t+b[i+k][1]>m:
            m=t+b[i+k][1]
            x=i
            y=b[i+k][0]
    print(x,y)