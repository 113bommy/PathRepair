t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    for j in range(n//2):
        print(a[n-1-j],end=" ")
        print(a[0])
        