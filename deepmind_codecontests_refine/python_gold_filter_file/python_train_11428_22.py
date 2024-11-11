n, x, m = map(int, input().split())
def am(a, b):
    return (a * a) % b
l = [x]
u = []
now = x
for i in range(n):
    s = am(now, m)
    if(s in l):
        break
    l.append(s)
    now = s
c = l.index(s)
k = 0
if(0 in l):
    print(sum(l))
else:
    for i in range(c):
        u.append(l.pop(0))
    a = (n-len(u)) // len(l)
    b = (n-len(u)) % len(l)
    print(sum(u) + a * sum(l) + sum(l[:b]))
