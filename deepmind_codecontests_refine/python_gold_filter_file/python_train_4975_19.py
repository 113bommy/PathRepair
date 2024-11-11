import sys;input=sys.stdin.readline
N, = map(int, input().split())
G = [set() for _ in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    G[a].add(b)
    G[b].add(a)

xs = [[] for _ in range(2)]
g2 = [set() for _ in range(N+1)]
vs = set()
stack = [1]
depth = [0]*(N+1)
dfs_vs = []
vs.add(1)
while stack:
    v = stack.pop()
    xs[depth[v] % 2].append(v)
    dfs_vs.append(v)
    for u in G[v]:
        if u in vs:
            continue
        depth[u] = depth[v] + 1
        g2[v].add(u)
        stack.append(u)
        vs.add(u)

xs.sort(key=lambda x:len(x))
rs = []
if len(xs[0]) <= N//3:
    i=j=k=0
    for x in xs[0]:
        i+=1
        rs.append((x, 3*i))
    for x in xs[1]:
        if i+1 <= N//3:
            i+=1
            rs.append((x, 3*i))
        elif j <= (N-1)//3:
            rs.append((x, 3*j+1))
            j+=1
        else:
            rs.append((x, 3*k+2))
            k+=1
else:
    i=j=k=0
    for x in xs[0]:
        if j <= (N-1)//3:
            rs.append((x, 3*j+1))
            j+=1
        elif i+1 <= N//3:
            i+=1
            rs.append((x, 3*i))
    for x in xs[1]:
        if i+1 <= N//3:
            i+=1
            rs.append((x, 3*i))
        else:
            rs.append((x, 3*k+2))
            k+=1

#print(rs)
rs.sort(key=lambda x:x[0])
print(" ".join(str(x[1]) for x in rs))
