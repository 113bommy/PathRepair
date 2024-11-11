n, k = map(int, input().split())

black = 0
imos = [[0 for i in range(k)] for j in range(k)]

for i in range(n):
    X, Y, C = input().split()
    x = int(X)
    y = int(Y)
    c = 1 if C == "W" else 0

    x = x % (2*k)
    y = y % (2*k)
    if x > k-1:
        x -= k
        c += 1
    if y > k-1:
        y -= k
        c += 1
    c = 1 if c%2 == 1 else -1
    imos[x][y] += c
    if c == -1:
        black += 1

for i in range(k):
    for j in range(k-1):
        imos[i][j+1] += imos[i][j]

for j in range(k):
    for i in range(k-1):
        imos[i+1][j] += imos[i][j]

ans = 0
for i in range(k):
    for j in range(k):
        m = imos[k-1][k-1] - imos[k-1][j] - imos[i][k-1] + 2 * imos[i][j]
        ans = max(ans, max(n-(black+m), black+m))
print(ans)