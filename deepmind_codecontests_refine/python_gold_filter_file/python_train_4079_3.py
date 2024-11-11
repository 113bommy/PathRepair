Q = int(input())
q = []
for _ in range(Q):
    N = int(input())
    X = []
    Y = []
    Xd = []
    Yd = []
    for _ in range(N):
        x, y, f1, f2, f3, f4 = map(int, input().split())
        X.append(x)
        Y.append(y)
        Xd.append([f1, f3])
        Yd.append([f4, f2])
    q.append([N, X, Y, Xd, Yd])
 
 
for qq in q:
    N, X, Y, Xd, Yd = qq
    ans = 1
 
    r = max(X)
    l = min(X)
    com = False
    for i, x in enumerate(X):
        if Xd[i][0] == 0:
            l = max(x, l)
        if Xd[i][1] == 0:
            r = min(x, r)
        if l > r:
            ans = 0
            break
        elif l == r:
            if not com:
                ax = l
                com = True
                continue
            if l != ax:
                ans = 0
                break  
    ax = l
    r = max(Y)
    l = min(Y)
    com = False
    for i, y in enumerate(Y):
        if Yd[i][0] == 0:
            l = max(y, l)
        if Yd[i][1] == 0:
            r = min(y, r)
        if l > r:
            ans = 0
            break
        elif l == r:
            if not com:
                ay = l
                com = True
                continue
            if l != ay:
                ans = 0
                break  
    ay = l
 
    if ans == 0:
        print(ans)
    else:
        print(ans, ax, ay)
 