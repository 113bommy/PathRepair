MOD = int(1e9) + 7

n = int(input())
w = [0] + list(map(int, input().split()))
q = [[] for i in range(n+1)]
p = [[] for i in range(n+1)]
m = int(input())
edges = [list(map(int, input().split())) for _ in range(m)]
for u, v in edges:
    p[u].append(v)
    q[v].append(u)
 
s, t = 0, 1
r = set(i for i in range(1, n+1) if not p[i] or not q[i])
while r:
    i = r.pop()
    s += w[i]
    for j in p[i]:
        q[j].remove(i)
        if not q[j]: 
            r.add(j)
    for j in q[i]:
        p[j].remove(i)
        if not p[j]: 
            r.add(j)
 
r = set(i for i in range(1, n+1) if p[i] and q[i])
while r:
    i = r.pop()
    h = p[i]
    d, k = w[i], 1
    while h:
        i = h.pop()
        if i not in r: 
            continue
        r.remove(i)
        h += p[i]
        if w[i] == d: 
            k += 1
        elif w[i] < d: 
            d, k = w[i], 1
    s += d
    t = (t * k) % MOD
print(s, t)