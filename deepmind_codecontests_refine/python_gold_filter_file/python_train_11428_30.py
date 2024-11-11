def resolve():
    n,x,m = map(int,input().split())
    ans = x
    y = [x]
    for i in range(n-1):
        x = (x**2)%m
        if x not in y:
            y.append(x)
        else:
            break
    b = y.index(x)
    N = len(y[b:])
    c = sum(y[b:])
    ans = sum(y[:b]) + c*((n-b)//N)+sum(y[b:b+(n-b)%N])
    print(ans)
resolve()