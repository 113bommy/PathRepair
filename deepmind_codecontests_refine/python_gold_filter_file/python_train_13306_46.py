l = int(input())
n = 1
ll = l
while ll > 1:
    n += 1
    ll = ll // 2
s = 1
e = []
while l > 1:
    h = l // 2
    e.append((s, s + 1, 0))
    e.append((s, s + 1, h))
    if l > h * 2:
        e.append((s, n, l - 1))
    l = h
    s += 1

print(n, len(e))
for x, y, w in e:
    print(x, y, w)