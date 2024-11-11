
t=int(input())
i=0
for i in range(0,t):
    x, y, n = [int(x) for x in input().split()]
    ans=0
    j=0
    if (n-n%x+y<=n):
        ans=n-n%x+y
    else:
        ans=n-n%x-(x-y)


    print(ans)

