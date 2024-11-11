from sys import stdin
input=stdin.readline
m=2**32-1
for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    ans=(a[k]+a[0])//2
    ra=(a[k]-a[0])
    for i in range(n-k):
        if (a[i+k]-a[i])<ra:
            ra=(a[i+k]-a[i])
            ans=(a[i+k]+a[i])//2
    print(ans)