def readln(): return tuple(map(int, input().split()))

n, d = readln()
a = []
b = []
for _ in range(n):
    p, q, t = input().split()
    t = int(t)
    if p > q:
        a.append((p, q, t))
    else:
        b.append((q, p, t))
ans = set()
for p, q, t in a:
    for p1, q1, t1 in b:
        if p == p1 and q == q1 and 0 < abs(t - t1) <= d:
            ans.add(p + ' ' + q)
print(len(ans))
print('\n'.join(ans))
