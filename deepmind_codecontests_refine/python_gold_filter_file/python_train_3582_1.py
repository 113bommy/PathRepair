n = 2 * int(input())
t = list(map(int, input().split()))
q, p, c = [0] * n, [0] * 100, [0, 0]
for i in t:
    p[i] += 1
for i in p:
    if i: c[i == 1] += 1
k = c[1] // 2
print((c[0] + k) * (c[0] + c[1] - k))
r = sorted([(p[j], j, i) for i, j in enumerate(t)])
for i in r[0: n: 2]:
    q[i[2]] = '1'
for i in r[1: n: 2]:
    q[i[2]] = '2'
print(' '.join(q))