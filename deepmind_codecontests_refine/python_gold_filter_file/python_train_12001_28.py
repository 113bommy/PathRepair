for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    l.sort()
    c = 0
    for i in range(1,n):
        if l[i] <k:
            c+=(k-l[i])//l[0]
    print(c)