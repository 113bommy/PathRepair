import sys
input = sys.stdin.readline
from collections import *

def bfs():
    q = deque([0])
    color = [0]*N
    color[0] = 1
    
    while q:
        v = q.popleft()
        
        for nv in G[v]:
            if color[nv]==0:
                color[nv] = -color[v]
                q.append(nv)
    
    return color

N = int(input())
G = [[] for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
    
cnt = [0]*3

for i in range(1, N+1):
    cnt[i%3] += 1

color = bfs()
m = color.count(1)
ans = [-1]*N

if m<=cnt[0]:
    c0, c1, c2 = 3, 1, 2
    
    for i in range(N):
        if color[i]==1:
            ans[i] = c0
            c0 += 3
    
    for i in range(N):
        if color[i]==-1:
            if c0<=N:
                ans[i] = c0
                c0 += 3
            else:
                if c1<=N:
                    ans[i] = c1
                    c1 += 3
                else:
                    ans[i] = c2
                    c2 += 3
elif m>=N-cnt[0]:
    c0, c1, c2 = 3, 1, 2
    
    for i in range(N):
        if color[i]==-1:
            ans[i] = c0
            c0 += 3
    
    for i in range(N):
        if color[i]==1:
            if c0<=N:
                ans[i] = c0
                c0 += 3
            else:
                if c1<=N:
                    ans[i] = c1
                    c1 += 3
                else:
                    ans[i] = c2
                    c2 += 3
else:
    c0, c1, c2 = 3, 1, 2
    
    for i in range(N):
        if color[i]==1:
            if c1<=N:
                ans[i] = c1
                c1 += 3
            else:
                ans[i] = c0
                c0 += 3
        
    for i in range(N):
        if color[i]==-1:
            if c0<=N:
                ans[i] = c0
                c0 += 3
            else:
                ans[i] = c2
                c2 += 3

print(*ans)