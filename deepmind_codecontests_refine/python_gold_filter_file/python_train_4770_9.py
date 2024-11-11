import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import itertools

N,MOD = map(int,readline().split())
m = map(int,read().split())
XY = zip(m,m)

mult = lambda x,y: x*y%MOD

graph = [[] for _ in range(N+1)]
for x,y in XY:
    graph[x].append(y)
    graph[y].append(x)

root = 1
parent = [0] * (N+1)
order = []
stack = [root]
while stack:
    x = stack.pop()
    order.append(x)
    for y in graph[x]:
        if y == parent[x]:
            continue
        parent[y] = x
        stack.append(y)

# 自身を黒く塗ったときの根側
dp1 = [0]*(N+1)

for v in order[::-1]:
    x = 1
    for w in graph[v]:
        x *= dp1[w]+1
        x %= MOD
    dp1[v] = x

# 親側
dp2 = [1]*(N+1)

for v in order:
    p = parent[v]
    arr = [dp1[c]+1 if c != p else dp2[v] for c in graph[v]]
    # 1元を除く積を取得
    from_left = [1] + list(itertools.accumulate(arr,mult))[:-1]
    from_right = list(itertools.accumulate(reversed(arr),mult))[-2::-1] + [1]
    prod = [x*y%MOD for x,y in zip(from_left,from_right)]
    for c,x in zip(graph[v],prod):
        if c != p:
            dp2[c] = 1+x

answer = '\n'.join(str(x*y%MOD) for x,y in zip(dp1[1:],dp2[1:]))
print(answer)