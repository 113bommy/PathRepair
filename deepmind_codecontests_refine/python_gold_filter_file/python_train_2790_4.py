import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def f(v, vs):
    kminmax = rkoma = fff = ffmx = 0
    for u in d[v]:
        if u in vs:
            continue
        vs.add(u)
        k1, koma, ff = f(u, vs)
        if k1 > kminmax:
            kminmax, ffmx = k1, ff
        rkoma += koma
        fff += ff
    r1 = kminmax+ffmx-fff if kminmax > fff - ffmx else fff % 2
    rkoma += km[v]
    return r1+rkoma, rkoma, fff+rkoma

N = int(input())
km = [0] + [int(i) for i in str(input().strip())]
d = [set() for _ in range(N+1)]
for _ in range(N-1):
    x, y = map(int, input().split())
    d[x].add(y)
    d[y].add(x)
r = 10**10
for i in range(N):
    a, c, fff = f(i+1, {i+1})
    if a == c:
        r = min((fff-c)//2, r)
print(r if r != 10**10 else -1)
