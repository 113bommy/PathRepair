for _ in range(int(input())):
    n = int(input())
    x = list(map(int,input().split()))
    c=0
    m=9999999
    for i in range(n-1,-1,-1):
        if m>=x[i]:
            m=x[i]
        else:
            c+=1
    print(c)