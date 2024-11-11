from sys import *
f = lambda: list(map(int, stdin.readline().split()))

class T:
    def __init__(self, i):
        self.i, self.t = i, f()[1:]
        self.a = self.q = 0

n, k = f()
d = f()
p = [None] + [T(i + 1) for i in range(n)]

s = []
while d:
    x = p[d.pop()]
    if x.a: continue
    d.append(x.i)
    q = 1
    for i in x.t:
        y = p[i]
        if y.a: continue
        d.append(y.i)
        q = 0
    if q:
        s.append(x.i)
        x.a = 1
    elif x.q:
        print(-1)
        exit()
    else: x.q = 1

print(len(s), *s)