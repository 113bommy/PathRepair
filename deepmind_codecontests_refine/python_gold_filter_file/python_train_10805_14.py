from collections import deque

n = int(input())
a = [list(map(lambda x:int(x)-1,input().split())) + [-1] for _ in range(n)]

l,day = [0]*n,[0]*n

que = deque([i for i in range(n)])

while que:
    u = que.popleft()
    v = a[u][l[u]]
    if a[v][l[v]] == u:
        day[u] = max(day[u],day[v]) + 1
        day[v] = day[u]
        l[u] += 1
        l[v] += 1
        que.append(u)
        que.append(v)

if any(x != n-1 for x in l):
    print(-1)
    exit()

print(max(day))
