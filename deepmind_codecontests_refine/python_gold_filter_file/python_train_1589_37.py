for i in range(int(input())):
    x,y,n=map(int,input().split())
    m=n//x
    ans=x*m+y
    if(ans>n):
        ans-=x
    print(ans)
