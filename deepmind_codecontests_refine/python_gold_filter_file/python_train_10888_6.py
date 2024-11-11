def solve():
    res = 1
    n,m,k = map(int,input().split())
    holes = [False]*(n+1)
    tmp = list(map(int,input().split()))
    for i in tmp:
        holes[i] = True
    if holes[1] == True:
        return 1
    else:
        while k != 0:
            k = k-1
            a,b = map(int,input().split())
            if holes[res] == True:
                continue
            if a == res:
                res = b
            elif b == res:
                res = a
    return res
print(solve())