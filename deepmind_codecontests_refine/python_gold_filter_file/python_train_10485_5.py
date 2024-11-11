a, b, c, n = list(map(int, input().split()))
if a + b - c >= n or c > a or c > b:
    print(-1)
else:
    print(n - (a + b - c))