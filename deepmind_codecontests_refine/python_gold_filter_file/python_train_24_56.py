t=int(input())
for T in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if(a[0]+a[1]<=a[n-1]):
        print(1,2,n)
    else:
        print(-1)