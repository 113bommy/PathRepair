def solve(n,m):
    #print(n,m)
    a = m[0][1]
    b = m[1][0]
    c = m[n-1][n-2]
    d = m[n-2][n-1]
    res = []
    if a ==b:
        if a == c:
            res.append([n,n-1])
        if a == d:
            res.append([n-1,n])
        
    elif c == d:
        if c == a:
            res.append([1,2])
        if b == c:
            res.append([2,1])
        
    else:
        #a == b and c == d 
        res.append([2,1])
        if a == c:
            res.append([n,n-1])
        if a == d:
            res.append([n-1,n])
    print(len(res))
    return res
        
t = int(input())

for _ in range(t):
    n = int(input())
    r = []
    c = n
    while n:
        x = list(input())
        r.append(x)
        n-=1 
    k = solve(c,r)
    for x in k:
        print(*x)