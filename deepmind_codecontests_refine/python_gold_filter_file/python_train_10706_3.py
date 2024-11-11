# -*- coding: utf-8 -*-
from collections import deque
n = int(input())
edge = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

inf = 10**6


fvisited = [inf for _ in range(n+1)]
fvisited[1] = 0
q = deque([1])
while len(q)>0:
    s = q.popleft()
    for e in edge[s]:
        if fvisited[e]==inf:
            fvisited[e] = fvisited[s]+1
            q.append(e)

svisited = [inf for _ in range(n+1)]
svisited[n] = 0
q = deque([n])
while len(q)>0:
    s = q.popleft()
    for e in edge[s]:
        if svisited[e]==inf:
            svisited[e] = svisited[s]+1
            q.append(e)

# print(fvisited)
# print(svisited)
fcnt = 0
scnt = 0
for i in range(1,n+1):
    if fvisited[i]<=svisited[i]:
        fcnt += 1
    else:
        scnt += 1

if fcnt>scnt:
    print("Fennec")
else:
    print("Snuke")
