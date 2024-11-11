# -*- coding: utf-8 -*-

# Baqir Khan
# Software Engineer (Backend)

n, m = map(int, input().split())
safe = n * n
ans = []
rows = set()
cols = set()

while m:
    m -= 1
    x, y = map(int, input().split())

    if x not in rows and y not in cols:
        safe -= (n + n - len(rows) - len(cols) - 1)
        rows.add(x)
        cols.add(y)

    if x in rows and y not in cols:
        safe -= (n - len(rows))
        cols.add(y)

    if x not in rows and y in cols:
        safe -= (n - len(cols))
        rows.add(x)

    ans.append(safe)

print(" ".join([str(a) for a in ans]))
