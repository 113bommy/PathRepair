N,M=map(int,input().split())
ab=list(list(map(int,input().split())) for _ in range(M))
graph=list([0]*N for _ in range(N))
ans=0
for a,b in ab:
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1

def dfs(s):
    visited[s]=1
    for i in range(N):
        if graph[s][i] == 0 or visited[i] == 1:
            continue
        dfs(i)

for a,b in ab:
    graph[a - 1][b - 1] = 0
    graph[b - 1][a - 1] = 0
    visited=[0]*N
    dfs(0)
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1
    if sum(visited)<N:
        ans+=1


print(ans)