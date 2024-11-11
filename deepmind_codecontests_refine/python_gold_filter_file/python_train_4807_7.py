n=int(input())
a=sorted(list(map(int,input().split())))
if a[n-1]>=a[n-2]+a[n-3]:
    print('NO')
else:
    print('YES')
    for i in range(n-1,-1,-2):
        print(a[i],end=' ')
    for i in range(n%2,n,2):
        print(a[i],end=' ')
