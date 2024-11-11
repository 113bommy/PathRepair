import sys
sys.setrecursionlimit(10**7)
from collections import deque

n,m = map(int,input().split())
if m == n-1:
  print(0)
  exit()
if 2*(n-m-1) > n:
    print("Impossible")
    exit()

e = [[] for i in range(n)]
a = list(map(int,input().split()))
for i in range(m):
    x,y = map(int,input().split())
    e[x].append(y)
    e[y].append(x)

def dfs(x):
    l = []
    d[x] = 1
    l.append(a[x])
    q = deque([])
    q.append(x)
    while q:
        now = q.pop()
        for nex in e[now]:
            if d[nex] > 0:
                continue
            l.append(a[nex])
            d[nex] = 1
            q.append(nex)
    l.sort()
    ans = l[0]
    
    for i in l[1:]:
        h.append(i)
    return ans
count = 2*(n-m-1)
d = [-1]*n
ans = 0
h = []
for i in range(n):
    if d[i] < 0:
        ans += dfs(i)
        count -= 1
if count > 0:
    h.sort()
    ans += sum(h[:count])
print(ans)

