import sys
input = sys.stdin.readline

def int_array():
	return list(map(int, input().strip().split()))

def float_array():
	return list(map(float, input().strip().split()))

def str_array():
	return input().strip().split()

def dfs():
	st=[(1,1)]
	while st:
		node,p=st.pop()
		vis[node]=1
		for v,k in g[node]:
			if vis[v]==0:
				if k==2:
					st.append((v,v))
					ans[v]=1
					ans[p]=0
				else:
					st.append((v,p))


from collections import Counter
import math
import bisect
from collections import deque
n=int(input())
vis=[0]*int(n+1)
g=[[] for i in range(n+1)]
for i in range(n-1):
	u,v,s=int_array()
	g[u].append((v,s))
	g[v].append((u,s))
ans=[0]*(n+1)
dfs()
print(ans.count(1))
for i in range(n+1):
	if ans[i]==1:
		print(i,end=" ")





