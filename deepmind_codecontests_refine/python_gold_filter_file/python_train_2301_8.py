n, k = map(int, input().split())
a = [int(e) for e in input().split()]
q = dict()
mx = len(set(a))
res = 0
m = 1
for i in a:
    q[i] = q.get(i, 0) + 1
for i in a:
    if q[i] > k and int(q[i] / k) >= m:
        m = q[i] / k
        if int(m) < m:
            m = int(m) + 1
        else:
            m = int(m)
mx = m * mx * k
print(mx - n)
