t = int(input())
for _ in range(t):
    s = str(input())
    t = str(input())
    INF = 10**18
    n = len(s)
    m = len(t)
    X = [[INF]*26 for i in range(n+5)]

    for i in reversed(range(n)):
        for j in range(26):
            X[i][j] = X[i+1][j]
        X[i][ord(s[i])-ord('a')] = i

    #print(X)
    ans = 1
    pos = 0
    for i in range(m):
        if pos == n:
            pos = 0
            ans += 1
        if X[pos][ord(t[i])-ord('a')] ==  INF:
            pos = 0
            ans += 1
            if  X[pos][ord(t[i])-ord('a')] ==  INF and pos == 0:
                ans = INF
                break
        pos = X[pos][ord(t[i])-ord('a')]+1
    if ans == INF:
        print(-1)
    else:
        print(ans)
