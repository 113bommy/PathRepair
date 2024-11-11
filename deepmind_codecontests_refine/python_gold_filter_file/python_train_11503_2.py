n, m = [int(x) for x in input().split()]
d = []
h = []
s = 0
amax = 0
for i in range(m):
    p, q = [int(x) for x in input().split()]
    d.append(p)
    h.append(q)
for i in range(m-1):
    if abs((h[i+1]-h[i]))/(d[i+1]-d[i]) > 1:
        print('IMPOSSIBLE')
        s += 1
        break
if s == 0:
    for i in range(m-1):
        lshift = h[i]-0
        rshift = h[i+1]-0
        a = d[i+1] + rshift - (d[i] - lshift)
        if a // 2 > amax:
            amax = a // 2
    b = h[0] + d[0] - 1
    c = h[m-1] + n - d[m-1]
    if amax >= b and amax >= c:
        print(amax)
    elif b >= amax and b >= c:
        print(b)
    else:
        print(c)
