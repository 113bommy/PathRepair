def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())

n = ii()
m = int(n ** 0.5)

a = [0] * n
c = 0
for i in range(10 ** 7):
    s = min(n, m * (i + 1))
    for j in range(m):
        a[c] = s
        s -= 1
        c += 1
        if c >= n: break
    if c >= n: break
print(*a)
