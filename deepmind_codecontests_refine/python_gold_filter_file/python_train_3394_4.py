f = lambda: map(int, input().split())
n, a = f()
d = [0] * 1000001
for q in f():
    if d[q] < d[a]: d[q] = -1
    d[q] += 1
k = d[a]
d[0] = d[a] = -1
s = -1
for i, q in enumerate(d):
    if q >= k:
        s = i
        break
print(s)