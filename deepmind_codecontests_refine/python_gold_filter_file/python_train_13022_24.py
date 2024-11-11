q, w = map(int, input().split())
e = [0] * (200)
for i in range(q):
    r, t = map(int,  input().split())
    if r == t:
        e[t] = 1
    else:
        for j in range(r,  t + 1):
            e[j] = 1
v = 0
b = []
for i in range(1,  w + 1):
    if e[i] == 0:
        v += 1
        b.append(i)
print(v)
print(*b)
