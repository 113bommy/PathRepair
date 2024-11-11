import math

def norm(p, q): # normal vector: (p -> q) * -1j
    return (q[1] - p[1], p[0] - q[0])

def magnitude(a):
    return (a[0]**2 + a[1]**2)**.5

def dot(p, q):
    return p[0]*q[0] + p[1]*q[1]

def angle(p, q):
    return math.acos(dot(p, q) / (magnitude(p) * magnitude(q)))

def cross(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])

def convex_hull(ps):
    ps = sorted(ps)
    qs = []
    n = len(ps)
    for p in ps:
        while len(qs) > 1 and cross(qs[-1], qs[-2], p) > 0:
            qs.pop()
        qs.append(p)
    t = len(qs)
    for i in range(n - 2, -1, -1):
        p = ps[i]
        while len(qs) > t and cross(qs[-1], qs[-2], p) > 0:
            qs.pop()
        qs.append(p)
    return qs

n = int(input())
s = [tuple(map(int, input().split())) for _ in range(n)]
ch = convex_hull(s)
ch.pop()
m = len(ch)
d = dict()
for i in range(m):
  u = angle(norm(ch[i-1], ch[i]), norm(ch[i], ch[(i+1)%m]))
  d[ch[i]] = u / 2 / math.pi
for t in s:
  print(0.0 if t not in d else d[t])