import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

from bisect import bisect

n = int(input())
x = list(map(int, input().split()))
l = int(input())

depth = [-1]*n
depth[-1] = 0

m = 20
par = [[-1]*n for i in range(m)]

def dfs(i):
    if depth[i] >= 0:
        return depth[i]
    j = bisect(x, x[i]+l)-1
    if j == n:
        j = n-1
    par[0][i] = j
    depth[i] = dfs(j) + 1
    return depth[i]

for i in range(n):
    dfs(i)

for i in range(m-1):
    for j in range(n):
        par[i+1][j]=par[i][par[i][j]]

def hoge(x, y):
# xからk個上の頂点がy以上になる最小のkを求める
    k = 0
    for i in range(m)[::-1]:
        if 0 <= par[i][x] < y:
            k += 1<<i
            x = par[i][x]
    return k+1

q = int(input())
ans = []
for i in range(q):
    a,b = map(int, input().split())
    a,b = a-1,b-1
    if a > b:
        a,b = b,a
    ans.append(hoge(a, b))

print(*ans, sep="\n")