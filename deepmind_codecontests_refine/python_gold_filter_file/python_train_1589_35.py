z=int(input())
for h in range(z):
    x,y,n=map(int,input().split())
    if x>n:
        print(y)
    else:
        m=n%x
        if y<=m:
            ans=n-(m-y)
        else:
            ans=n-m-(x-y)
        print(ans)