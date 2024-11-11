t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if(a[n-1]>=a[0]+a[1]):
        print(1,2,n)
    else:
        print(-1)