# -*- coding: utf-8 -*-

### Union Find (Meguru ver.) ###
 
from collections import defaultdict as ddict
 
MAX_N = 1000
 
uni = [0] * MAX_N
 
graph = ddict(set)
 
def init(n):
    for i in range(n):
        uni[i] = -1
    
def root(x):
    if uni[x] < 0:
        return x
    else:
        uni[x] = root(uni[x])
        return uni[x]
 
def same(x, y):
    return root(x) == root(y)
 
def unite(x, y):
    x = root(x)
    y = root(y)
    
    if(x == y):
        return
    
    if uni[x] > uni[y]:
        x, y = y, x
    
    uni[x] += uni[y]
    
    uni[y] = x

def nC2(n):
    return n * (n - 1) // 2

N, M = map(int, input().split())
 
#initialize array uni[]
init(N)

#make graph
for i in range(M):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    if u > v:
        u, v = v, u
    graph[u].add(v)
    graph[v].add(u)

#check points to be 'b'
b = set()
for i in range(N):
    if len(graph[i]) == N - 1:
        b.add(i)

#make UnionFind-tree without b
for i in range(N):
    for j in graph[i]:
        if not i in b and not j in b:
            unite(i, j)
            
#num of group
cnt = 0

flag = True

parent = 0

for r in range(N):
    if not r in b and uni[r] < 0:

        if cnt >= 2:
            flag = False
            break
        
        #check if this group is a perfect graph
        for i in range(N):
            if same(i, r) and len(graph[i] - b) != -uni[r] - 1:
                flag = False
                break
        
        if not flag:
            break
        
        cnt += 1
        
        #use after
        parent = r

if flag:
    print("Yes")
    
    s = ""
    for i in range(N):
        if i in b:
            s += 'b'
        elif same(i, parent):
            s += 'a'
        else:
            s += 'c'
    
    print(s)
else:
    print("No")