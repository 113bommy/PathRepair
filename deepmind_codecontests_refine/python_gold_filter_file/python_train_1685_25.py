for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    c = 0
    m = 100000000000
    for i in range(n-1,-1,-1):
        if m>=l[i]:
            m = l[i]
        else:
            c+=1
    print(c)



