import queue

N = int(input())

# Adjacency matrix
e = [[] for i in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

even_v = []
odd_v = []

is_reached = [False] * (N+1)
q = queue.Queue()
# [start vertex, total distance]
q.put([1, 0])

# BFS
while not q.empty():
    v, d = q.get()
    if is_reached[v]:
        continue
    is_reached[v] = True
    
    if d%2 == 0:
        even_v.append(v)
    else:
        odd_v.append(v)

    for tv in e[v]:
        q.put([tv, d+1])

# Remainder lists [1..N] mod 3
r1 = list(range(1, N+1, 3))
r2 = list(range(2, N+1, 3))
r3 = list(range(3, N+1, 3))

p = [0] * N
if len(even_v) <= len(r3):
    # Embed r3 in even_v
    for v in even_v:
        p[v-1] = r3.pop()
elif len(odd_v) <= len(r3):
    # Embed r3 in odd_v
    for v in odd_v:
        p[v-1] = r3.pop()
else:
    # Embed r1 in even_v
    for v in even_v:
        if not r1:
            break
        p[v-1] = r1.pop()
    # Embed r2 in odd_v
    for v in odd_v:
        if not r2:
            break
        p[v-1] = r2.pop()

# Collect unused vertexes
rv = []
rv.extend(r1)
rv.extend(r2)
rv.extend(r3)
for i, _ in enumerate(p):
    if p[i] == 0:
        p[i] = rv.pop()

ans = ' '.join(list(map(str, p)))
print(ans)
