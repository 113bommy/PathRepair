n, k = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)
if k % 2 == 0:
    ans = 100000
    for i in range(n):
        s = [i]
        d = [-1] * n
        d[i] = 0
        while s:
            p = s.pop()
            for node in g[p]:
                if d[node] == -1:
                    s.append(node)
                    d[node] = d[p] + 1
        c = 0
        for i in range(n):
            if d[i] > k // 2:
                c += 1
        ans = min(ans, c)
else:
    ans = 100000
    for i in range(n):
        for j in g[i]:
            s = [i, j]
            d = [-1] * n
            d[i] = 0
            d[j] = 0
            while s:
                p = s.pop()
                for node in g[p]:
                    if d[node] == -1:
                        s.append(node)
                        d[node] = d[p] + 1
            c = 0
            for p in range(n):
                if d[p] > k // 2:
                    c += 1
            ans = min(ans, c)
print(ans)
