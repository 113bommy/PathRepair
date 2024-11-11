from collections import deque
n, u, v = map(int,input().split())
tree = [[] for _ in range(n+1)]
for _i in range(n-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)


def solve(x):
    visit = [-1 for _ in range(n+1)]
    visit[x] = 0
    q = deque([x])
    while q:
        p = q.popleft()
        for i in tree[p]:
            if visit[i] < 0:
                visit[i] = visit[p]+1
                q.append(i)
    return visit

visit_a = solve(v)
visit_t = solve(u)

x, y = [], []
for i in range(1, n+1):
    if visit_a[i] >= visit_t[i]:
        x.append(visit_a[i])
        y.append(visit_t[i])
p = x.index(max(x))

print(x[p]-1)