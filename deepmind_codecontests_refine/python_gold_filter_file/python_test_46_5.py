t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    x1=a.index(max(a))
    x2=max(a)
    c=0
    p=a[-1]
    if p==x2:
        print(0)
    else:
        for j in range(n-2,x1-1,-1):
            if p==x2:
                break
            elif a[j]>p:
                p=a[j]
                c=c+1
        print(c)