n=int(input())
a=list(map(int,input().split()))

if n==1:
    print(f'1 1')
    print(-a[0])
    print(f'1 1')
    print(0)
    print(f'1 1')
    print(0)
else:
    print(f'1 {n-1}')
    for i in range(n-1):
        print(a[i]*(n-1),end=" ")
        a[i]=a[i]*n
    print()

    print(f'{n} {n}')
    print(a[n-1]*(n-1))
    a[n-1]=a[n-1]*n

    print(f'1 {n}')
    for i in range(n):
        print(-a[i],end=' ')
        a[i]=0
    print()


