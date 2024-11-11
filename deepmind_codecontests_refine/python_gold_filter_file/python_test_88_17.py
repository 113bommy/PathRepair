for t in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if n%2==0:
        print('YES')
    else:
        f=0
        for i in range(n-1):
            if a[i]>=a[i+1]:
                f=1
                break
        if f:
            print('YES')
        else:
            print('NO')