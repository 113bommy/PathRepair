from sys import exit
import queue
V,E = [int(n) for n in input().split()]
ans = []

# N = int(input())
graph = [[] for _ in range(V)]
indeg = [0]*V
yet = [True]*V
def bfs(s):
    q = queue.Queue()
    q.put(s)
    while(not q.empty()):
        u = q.get()
        ans.append(u)
        yet[u]=False
        for v in graph[u]:
            indeg[v]-=1
            if(indeg[v]==0):
                q.put(v)

for i in range(E):
    s, t = [int(n) for n in input().split()]
    graph[s].append(t)
    indeg[t]+=1
for i in range(V):
    if(indeg[i]==0 and yet[i]):
        bfs(i)
for a in ans:
    print(a)
# a = [int(input()) for _ in range(N)]
# S = str(input())
# L = len(S)
# T = str(input())
# exit()

