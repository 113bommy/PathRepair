for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=0
    for i in range(n):
        b=max(b,a[i]-i-1)
    print(b)

