import collections

K = int(input())

q = collections.deque([(1, 0)])
v = {1}

while len(q) > 0:
    c, p = q.popleft()
    v.add(c)
    if c == 0:
        break

    n1, n10 = (c + 1) % K, (c * 10) % K
    if not n1 in v:
        q.append((n1, p + 1))
    if not n10 in v:
        q.appendleft((n10, p))

print(p + 1)
