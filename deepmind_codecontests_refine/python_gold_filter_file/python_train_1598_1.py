from collections import *

f = lambda: list(map(int, input().split()))
n, l, a = f()
p, s = f(), f()
m = s.count(-1)
x = {(0, min(a, m)): 1}
d = [1]

for p, s in zip(p, s):
    p /= 100
    if s > 0:
        y = defaultdict(int)
        for (k, a), q in x.items():
            y[(k, a)] += q - q * p
            y[(min(l, k + 1), min(m, a + s))] += q * p
        x = y
    else:
        d = [(a - b) * p + b for a, b in zip([0] + d, d + [0])]

y = [[0] * (m + 2) for i in range(n - m + 2)]
for k, a in x:
    if k + a >= l: y[k][a] = x[(k, a)]

for k in range(n - m, -1, -1):
    for a in range(m, -1, -1):
        y[k][a - 1] += y[k][a]
        y[k][a] += y[k + 1][a]

print(sum(y[max(0, l - k)][k] * p for k, p in enumerate(d) if l - k <= n - m))