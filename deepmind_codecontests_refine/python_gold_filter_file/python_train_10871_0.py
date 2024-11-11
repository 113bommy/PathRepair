q = 10001
n, a = int(input()), list(map(int, input().split()))
a.sort()
for i in range(40000 // (n - 1) + 1):
    b = [a[j] - j * i for j in range(n)]
    u, v = max(b), min(b)
    p = (u - v + 1) // 2
    if p < q: q, s, d = p, v + p, i
print(q)
print(s, d)

