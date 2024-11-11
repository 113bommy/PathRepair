for t in range(int(input())):
    n,m,x,y=map(int,input().split())
    ans=0
    for i in range(n):
        l=list(input().split("*"))
        for j in l:
            a=len(j)
            ans+=((a//2)*min(2*x,y)+(a%2)*x)
    print(ans)