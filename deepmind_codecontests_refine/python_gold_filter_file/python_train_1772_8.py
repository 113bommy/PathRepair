import sys
from operator import itemgetter, attrgetter
from itertools import starmap
import cmath
from math import isinf, sqrt, acos, atan2
readline = sys.stdin.readline
EPS = 1e-9
ONLINE_FRONT = -2
CLOCKWISE = -1
ON_SEGMENT = 0
COUNTER_CLOCKWISE = 1
ONLINE_BACK = 2
class Circle(object):
    __slots__ = ('c', 'r')
    def __init__(self, c, r):
        self.c = c
        self.r = r
class Segment(object):
    __slots__ = ('fi', 'se')
    def __init__(self, fi, se):
        self.fi = fi
        self.se = se
Line = Segment
def cross(a, b):
    return a.real * b.imag - a.imag * b.real
def dot(a, b):
    return a.real * b.real + a.imag * b.imag
def norm(base):
    return abs(base) ** 2
def project(s, p2):
    base = s.fi - s.se
    r = dot(p2 - s.fi, base) / norm(base)
    return s.fi + base * r
def reflect(s, p):
    return p + (project(s, p) - p) * 2.0
def ccw(p1, p2, p3):
    a = p2 - p1
    b = p3 - p1
    if cross(a, b) > EPS: return 1
    if cross(a, b) < -EPS: return -1
    if dot(a, b) < -EPS: return 2
    if norm(a) < norm(b): return -2
    return 0
def intersect4(p1, p2, p3, p4):
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and
			ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0)
def intersect2(s1, s2):
    return intersect4(s1.fi, s1.se, s2.fi, s2.se)
def getDistance(a, b):  return abs(a - b)
def getDistanceLP(l, p):
    return abs(cross(l.se - l.fi, p - l.fi) / abs(l.se - l.fi))
def getDistanceSP(s, p):
    if dot(s.se - s.fi, p - s.fi) < 0.0: return abs(p - s.fi)
    if dot(s.fi - s.se, p - s.se) < 0.0: return abs(p - s.se)
    return getDistanceLP(s, p)
def getDistances(s1, s2):
    if intersect2(s1, s2): return 0.0
    return min(getDistanceSP(s1, s2.fi), getDistanceSP(s1, s2.se),
               getDistanceSP(s2, s1.fi), getDistanceSP(s2, s1.se))
def getCrossPoint(s1, s2):
	base = s2.se - s2.fi
	d1 = abs(cross(base, s1.fi - s2.fi))
	d2 = abs(cross(base, s1.se - s2.fi))
	t = d1 / (d1 + d2)
	return s1.fi + (s1.se - s1.fi) * t
def getCrossPointsCL(c, l):
    pr = project(l, c.c)
    e = (l.se - l.fi) / abs(l.se - l.fi)
    base = sqrt(c.r * c.r - norm(pr - c.c))
    return Segment(*sorted((pr + e * base, pr - e * base)), key=attrgetter('real', 'imag'))
def getCrossPointsCC(c1, c2):
    d = abs(c1.c - c2.c)
    a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2.0 * c1.r * d))
    t = cmath.phase(c2.c - c1.c)
    return Segment(*sorted((c1.c + cmath.rect(c1.r, t + a), c1.c + cmath.rect(c1.r, t - a)), key=attrgetter('real', 'imag')))
def contains(g, p):
    n = len(g)
    x = False
    for i in range(n):
        a = g[i] - p
        b = g[(i + 1) % n] - p
        if abs(cross(a, b)) < EPS and dot(a, b) < EPS: return 1
        if a.imag > b.imag: a, b = b, a
        if a.imag < EPS and EPS < b.imag and cross(a, b) > EPS: x = not x
    return 2 if x else 0
def andrewScan(s):
    if len(s) < 3: return s
    u = []
    l = []
    s.sort(key=attrgetter('imag'))
    u.append(s[0])
    u.append(s[1])
    l.append(s[-1])
    l.append(s[-2])
    _ccw = 0
    for i in range(2, len(s)):
        for q in range(len(u), 1, -1):
            _ccw = ccw(u[q - 2], u[q - 1], s[i])
            if not (_ccw != CLOCKWISE and _ccw != ONLINE_FRONT): break
            u.pop()
        u.append(s[i])
    for i in range(len(s) - 3, -1, -1):
        for q in range(len(l), 1, -1):
            _ccw = ccw(l[q - 2], l[q - 1], s[i])
            if not (_ccw != CLOCKWISE and _ccw != ONLINE_FRONT): break
            l.pop()
        l.append(s[i])
    return l[::-1] + u[1:len(u) - 1][::-1]
n = int(readline())
pg = [complex(*map(int, readline().split())) for _ in [0] * n]
ans = andrewScan(pg)
print(len(ans))
for i in range(len(ans)):
    print(int(ans[i].real), int(ans[i].imag))