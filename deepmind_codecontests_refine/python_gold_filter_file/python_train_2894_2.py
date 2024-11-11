N,Q = map(int,input().split())

adj = [list() for _ in range(N)]
for _ in range(N-1):
    a,b = map(int,input().split())
    adj[a-1].append(b-1)

memo = [0]*N
for _ in range(Q):
    p,x = map(int,input().split())
    memo[p-1] += x

result = [None]*N
stack = [(0,0)]
while stack:
    v,a = stack.pop()
    a += memo[v]
    result[v] = a
    for u in adj[v]:
        stack.append((u,a))

print(*result)