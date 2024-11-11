for _ in range(int(input())):
    n = int(input())
    x = list(map(int,input().split()))
    c=0
    m=x[n-1]
    for i in range(n-2,-1,-1):
        if m>=x[i]:
            m=x[i]
        else:
            c+=1
    print(c)