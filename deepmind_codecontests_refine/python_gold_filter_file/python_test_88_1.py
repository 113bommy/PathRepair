for i in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    if n%2==0:
        print('YES')
    else:
        for i in range(n-1):
            if a[i]>=a[i+1]: 
                print('YES')
                break
        else:
            print('NO')