f = lambda x, y, d: (abs(y - x) + d - 1)//d

for _ in range(int(input())):
    n, x, y, d = map(int, input().split())
    res = float('INF')
    if y % d == x % d:
        res = f(x, y, d)
    if y % d == 1:
        res = min(res, f(x, 1, d) + f(1, y, d))
    if y % d == n % d:
        res = min(res, f(x, n, d) + f(n, y, d))
    if res == float('INF'):
        res = -1
    print(res)