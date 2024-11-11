from functools import lru_cache
import sys
sys.setrecursionlimit(10**7)

n,m,*l=map(int,open(0).read().split())
graph=[[]*n for _ in range(n)]
unvis=[True]*n

@lru_cache(maxsize=None)
def dfs(x):
	for y in graph[x]:
		if unvis[y]:
			unvis[y]=False
			dfs(y)
			
for i,j in zip(l[::3],l[1::3]):
	graph[i-1].append(j-1)
	graph[j-1].append(i-1)

ans=0
for x in range(n):
	if unvis[x]:
		unvis[x]=False
		dfs(x)
		ans+=1
print(ans)
