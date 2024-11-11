n,u,v = map(int, input().split( ))
u-=1
v-=1
Tr = [[] for _ in range(n)]
for i in range(n-1):
    ai,bi = map(int, input().split( ))
    ai -=1
    bi-=1
    Tr[ai].append(bi)
    Tr[bi].append(ai)

Dep_u = [-1] *n 
Dep_v = [-1] *n

Dep_u[u] = 0
Dep_v[v] = 0

from collections import deque
##bfs2回が簡明
def bfs(L,x):
    Q = deque()
    Q.append(x)
    while Q:
        y = Q.popleft()
        for z in Tr[y]:
            if L[z] == -1:
                L[z] = L[y] + 1
                Q.append(z)
                
bfs(Dep_u,u)
bfs(Dep_v,v)

ans = 0###0から

for i in range(n):
    if Dep_v[i]>Dep_u[i]:
        ans = max(ans,Dep_v[i]-1)###v
print(ans)



