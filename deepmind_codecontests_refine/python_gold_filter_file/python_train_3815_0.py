n, m = map(int, input().split())

p, r = list(range(n + 1)), [0] * (n + 1)

def find(x):
    if p[x] != x:
        p[x] = find(p[x])
    return p[x]

def union(x, y):
    x, y = find(x), find(y)
    if x == y: return 0
    if r[x] < r[y]: x, y = y, x
    p[y] = x
    r[x] += r[x] == r[y]
    return 1
    

MOD = 10 ** 9 + 9
ans = 1
out = []
for _ in range(m):
    u, v = map(int, input().split())
    if not union(u, v):
        ans = (ans << 1) % MOD
    out.append((ans + MOD - 1) % MOD)
print(*out, sep='\n')