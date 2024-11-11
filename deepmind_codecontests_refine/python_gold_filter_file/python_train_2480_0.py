from collections import Counter
import sys
def muri():
    print(-1)
    sys.exit()
N = int(input())
D = [int(sys.stdin.readline()) for _ in range(N)]
#D = list(map(int, input().split()))
Didx = list(range(1, N+1))
Didx.sort(key = lambda x: -D[x-1])
H = {d: i for i, d in enumerate(D, 1)}
H = Counter(H)
D = [0] + D
K = [1]*(N+1)
Ans = []
for vn in Didx[:-1]:
    p = H[D[vn] - (N - 2*K[vn])]
    if not p:
        muri()
    Ans.append((vn, p))
    K[p] += K[vn]
s = set()

Edge = [[] for _ in range(N+1)]
for a in Ans:
    x, y = a
    Edge[x].append(y)
    Edge[y].append(x)

dist = [10**9+7]*(N+1)
dist[0] = 0
dist[1] = 0
stack = [1]
visited = set([1])
while stack:
    vn = stack.pop()
    for vf in Edge[vn]:
        if vf not in visited:
            visited.add(vf)
            dist[vf] = 1 + dist[vn]
            stack.append(vf)
if D[1] != sum(dist[1:]):
    muri()

for a in Ans:
    print(*a)