n = int(input())
p = [set() for i in range(n)]
for k in range(n - 1):
    u, v = map(int, input().split())
    p[u - 1].add(v - 1)
    p[v - 1].add(u - 1)

s = [(0, 0)] * n
t = [(0, 1 << 30, 7)]
l = [1, 0, -1, 0, 1]

while t:
    u, d, j = t.pop()
    x, y = s[u]
    i = 0
    for v in p[u]:
        if i == j: i += 1
        if i > 3: exit(print('NO'))
        p[v].remove(u)
        s[v] = (x + l[i] * d, y + l[i + 1] * d)
        t.append((v, d >> 1, (i + 2) % 4))
        i += 1

print('YES')
for x, y in s: print(x, y)