n,k=map(int,input().split())
if n==3:print("1 2 3")
else:
    ans=3
    t=180/n
    for i in range(4,n+1):
        if abs(k-(i-2)*t)<abs(k-(ans-2)*t):
            ans=i
    print(*[2,1,ans])

