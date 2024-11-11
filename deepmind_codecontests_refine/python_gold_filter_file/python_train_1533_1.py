n, m = map(int, input().split())
a = [list(map(int, input())) for i in range(n)]
counts = [sum(a[i][j] for i in range(n)) for j in range(m)]
isIgnorable = all(any(a[i][j] == counts[j] for j in range(m)) for i in range(n))
print("NO" if isIgnorable else "YES")
