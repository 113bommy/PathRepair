import sys
sys.setrecursionlimit(10**9)

n, m = map(int, input().split())
xyz = [[] for i in range(n+1)]
for _ in range(m):
    x, y, z = map(int, input().split())
    xyz[x].append(y)
    xyz[y].append(x)
    
ans = 0
visited = [False]*(n+1)
def dfs(x):
    visited[x] = True
    for y in xyz[x]:
        if not visited[y]:
            dfs(y)

for x in range(1, n+1):
    if visited[x]:
        continue
    dfs(x)
    ans += 1
    
# print(visited)
print(ans)
