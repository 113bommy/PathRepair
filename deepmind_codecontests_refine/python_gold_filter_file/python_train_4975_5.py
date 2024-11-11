import sys
from collections import deque
sys.setrecursionlimit(1000000)
readline = sys.stdin.buffer.readline
n = int(readline())

g = [[] for _ in range(n+1)] #隣接リスト
for i in range(n-1):
    a,b = map(int,readline().split())
    g[a].append(b)
    g[b].append(a)

colors = [0] * (n+1)
 
colors[1] = 1
 
todo = []
for to in g[1]:
    todo.append([to, -1])
 
while todo:
    node, color = todo.pop()
 
    if colors[node] != 0:
        continue
 
    colors[node] = color
    new_color = -color
    for to in g[node]:
        if colors[to] != 0:
            continue
        todo.append([to, new_color])
ans = [0]*(n+1)
t0 = deque([])
t1 = deque([])
t2 = deque([])
for i in range(1,n+1):
    if i%3==1:
        t1.append(i)
    elif i%3==2:
        t2.append(i)
    else:
        t0.append(i)
black = 0
for i in colors[1:]:
    if i == 1:
        black += 1

if black <= n//3:
    for i in range(1,n+1):
        if colors[i] == 1:
            ans[i] = t0.pop()
        else:
            if t1:
                ans[i] = t1.pop()
            elif t2:
                ans[i] = t2.pop()
            else:
                ans[i] = t0.pop()
elif black >= n-n//3:
    for i in range(1,n+1):
        if colors[i] == -1:
            ans[i] = t0.pop()
        else:
            if t1:
                ans[i] = t1.pop()
            elif t2:
                ans[i] = t2.pop()
            else:
                ans[i] = t0.pop()
else:
    for i in range(1,n+1):
        if colors[i] == 1:
            if t1:
                ans[i] = t1.pop()
            else:
                ans[i] = t0.pop()
        else:
            if t2:
                ans[i] = t2.pop()
            else:
                ans[i] = t0.pop()
print(*ans[1:])