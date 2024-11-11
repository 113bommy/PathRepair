t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    temp=0
    x=set(a)
    y=set(b)
    c=list(x)
    d=list(y)
    c.sort()
    d.sort()
    for i in range(0,len(c)):
        if(c[i] in d):
            temp=1
            p=c[i]
            break
    if(temp==1):
        print("YES")
        print(temp,p)
    else:
        print("NO")