a, b = [int(i) for i in input().split()]
c = list(map(int,input().split()))
d, h= 0, 0
e = []
f = []
g = []
def allow():
    while f[0][0] < h:
        del f[0]
    while g[0][0] < h:
        del g[0]
    return f[0][1] - g[0][1] <= b
for i in range(a):
    while len(f) > 0 and f[-1][1] <= c[i]:
        del f[-1]
    f.append((i, c[i]))
    while len(g) > 0 and g[-1][1] >= c[i]:
        del g[-1]
    g.append((i, c[i]))
    while not allow():
        h += 1
    if i - h + 1 > d:
        d = i - h + 1
        e = [i]
    elif i - h + 1 == d:
        e.append(i)
print(d, len(e))
for i in e:
    i += 1
    print(i - d + 1, i)
