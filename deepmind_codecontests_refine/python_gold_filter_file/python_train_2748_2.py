n, m = map(int, input().split())
k = n + 1
a, b = [False] * k, [False] * k
for i in range(m):
    x, y = map(int, input().split())
    a[x] = True
    b[y] = True
s = a[2: n].count(False) + b[2: n].count(False)
if n & 1 and not (a[k // 2] or b[k // 2]): s -= 1
print(s)