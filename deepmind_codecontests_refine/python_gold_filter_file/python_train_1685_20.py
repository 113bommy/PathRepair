for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    cnt=0
    min=a[n-1]
    for i in range(n-2,-1,-1):
        if a[i]<=min:
            min=a[i]
        else:
            cnt += 1
    print(cnt)

