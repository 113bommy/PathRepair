n, q = map(int, input().split())
s = input()
ts, ds = [], []
for _ in range(q):
    t, d = input().split()
    ts.append(t)
    ds.append(d)

def reachable(n, dest):
    for t, d in zip(ts, ds):
        if s[n] == t:
            n = n - 1 if d == 'L' else n + 1
        if n == dest:
            return True
        elif not 0 <= n <= len(s) - 1:
            return False
    return False


l, r = -1, n
while r - l > 1:
    m = l + (r - l) // 2
    if reachable(m, -1):
        l = m
    else:
        r = m
ldel = l + 1

l, r = -1, n
while r - l > 1:
    m = l + (r - l) // 2
    if reachable(m, n):
        r = m
    else:
        l = m
rdel = n - r

print(max(n - (ldel + rdel), 0))
