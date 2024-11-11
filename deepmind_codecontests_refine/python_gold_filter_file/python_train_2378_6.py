import sys
sys.setrecursionlimit(10**7)

def dfs(v, color):
    colors[v] = color
    for to in g[v]:
        if colors[to] == color: return False
        if colors[to] == 0 and not dfs(to, -color):
            return False
    return True

n, m = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

colors = [0]*n

ans = -m
if dfs(0,1):
  b = (sum(colors)+n)//2
  w = n-b
  ans += b*w
else:
  ans += n*(n-1)//2
print(ans)