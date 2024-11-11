N, K = map(int, input().split())
E = [set() for i in range(N+1)]
Er = []
for i in range(N-1):
    a, b = map(int, input().split())
    E[a].add(b)
    E[b].add(a)
    Er.append({a, b})
ma = 0
Start = []
if K&1 == 1:
    Start = Er
else:
    Start = [{i} for i in range(1, N+1)]
for st in Start:
    L = list(st)
    Closed = st
    for j in range(K//2):
        S = []
        for l in L:
            S += E[l]
        L = []
        for s in S:
            if s not in Closed:
                L.append(s)
                Closed.add(s)
    ma = max(ma, len(Closed))
print(N-ma)
