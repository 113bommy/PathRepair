read = lambda: map(int, input().split())
n, a = read()
ans = -1
opt = 1000
for i in range(3, n + 1):
    cur = abs((180 / n * (n - i + 1)) - a)
    if cur < opt:
        opt = cur
        ans = i
print(1, 2, ans)