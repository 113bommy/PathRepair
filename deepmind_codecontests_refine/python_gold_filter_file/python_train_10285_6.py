import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline

mod = 10**9+7

n = int(input())
g = [[] for _ in range(n)]

pow2 = [0 for _ in range(n+1)]
pow2[0] = 1
for i in range(n):
    pow2[i+1] = pow2[i]*2 %mod

for _ in range(n-1):
    a,b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

depth = [-1]*n
ko_all = [0 for _ in range(n)]
ko_only =[0 for _ in range(n)]

def dfs(v,d):
    depth[v] = d
    for w in g[v]:
        if depth[w] == -1:
            dfs(w,d+1)
            ko_all[v] += ko_all[w]+1
            ko_only[v] += pow2[ko_all[w]+1]-1

dfs(0,0)

cnt = 0

for i in range(n):
    tmp = pow2[n-1]-1-(pow2[n-1-ko_all[i]]-1) - ko_only[i]
    tmp %=mod
    cnt += tmp
    cnt %= mod

def inv(a,mod):
    r = [1,0,a]
    w = [0,1,mod]
    while w[2]!=1:
        q = r[2]//w[2]
        r_new = [r[0]-q*w[0],r[1]-q*w[1],r[2]-q*w[2]]
        r = w
        w = r_new
    x,y = w[0],w[1]    # a*x+y*mod = 1
    return (mod+x%mod)%mod

print(inv(pow2[n],mod)*cnt %mod)
