from collections import Counter

n = int(input())
mat = []
cnt = 0
p = Counter()
q = Counter()
r = Counter()
for _ in range(n):
    x, y = map(int, input().split())
    mat.append([x, y])
for i in range(n):
    a = mat[i][0]
    b = mat[i][1]
    if p[a]:
        p[a] += 1
    else:
        p[a] = 1
    if q[b]:
        q[b] += 1
    else:
        q[b] = 1
    if r[str(a) + str(b)]:
        r[str(a) + str(b)] += 1
    else:
        r[str(a) + str(b)] = 1
for i in p.values():
    cnt += (i * (i - 1)) // 2
for j in q.values():
    cnt += (j * (j - 1)) // 2
for k in r.values():
    cnt -= (k * (k - 1)) // 2
print(cnt)
