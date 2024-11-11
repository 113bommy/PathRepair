n, ans = int(input()), 1
a = [[1]*n]*n


def f(u, v):
    global a
    a[u][v] = a[u-1][v] + a[u][v-1]
    return a[u][v]


for x in range(1, n):
    for y in range(1, n):
        ans = max(ans, f(x, y))

print(ans)