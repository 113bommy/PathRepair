N = int(input())
X = [0] * N
ans = 0
for i in range(N-1):
    x, y = map(int, input().split())
    x, y = x-1, y-1
    if x > y: x, y = y, x
    ans += (y - x) * (N - y + x + 1)
    X[x] += 1
    X[y] += 1
for i, x in enumerate(X):
    ans += (i + 1) * (N - i) * (2 - x)
print(ans // 2)