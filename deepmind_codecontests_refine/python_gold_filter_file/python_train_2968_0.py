p, q = map(int, input().split())
n = 1200000
t = [0, q] * 600000
for i in range(3, 1096, 2):
    if t[i]:
        for j in range(i * i, n, i): t[j] = 0
t[1], t[2] = -p, q - p
for i in range(3, 10): t[i] -= p
for i in range(1, 1000):
    u = str(i)
    v = u[::-1]
    for j in '0123456789':
        k = int(u + j + v)
        if k < n: t[k] -= p
    t[int(u + v)] -= p
j = s = 0
for i, q in enumerate(t):
    s += q
    if s <= 0: j = i
print(j)