for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = {}
    e = [-1 for i in range(n)]
    for i in range(n):
        if a[i] in d:
            d[a[i]].append(i)
        else:
            d[a[i]] = [-1, i]
    for i in sorted(d):
        d[i].append(n)
        mx = 0
        for j in range(len(d[i]) - 1):
            mx = max((d[i][j + 1] - d[i][j]) - 1, mx)
        for k in range(mx, n):
            if e[k] != -1:
                break
            e[k] = i
    print(*e)
