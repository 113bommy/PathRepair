from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

N = inp()
lines = [[] for _ in range(N)]
for i in range(N-1):
    a,b = inpl()
    a-=1; b-=1
    lines[a].append((b,i))
    lines[b].append((a,i))


def dfs(s,b,v):
    if s == v:
        return set()
    else:
        for t,i in lines[s]:
            if t == b:
                continue
            ret = dfs(t,s,v)
            if ret is not None:
                ret.add(i)
                return ret

        return None


M = inp()
mm = [] # i 番目の条件は mm[i] のラインのどこかに +1 をする
for m in range(M):
    u,v = inpl()
    u-=1; v-=1
    mm.append(dfs(u,-1,v))



dp = [0] * (1<<M)
dp[0] = 1

for i in range(N-1):
    # line i を白くした場合
    # dp[:] = dp[:]
    # line i を黒くした場合
    tmp = 0
    for b,m in enumerate(mm):
        if i in m:
            tmp += (1<<b)

    for b in reversed(range(1<<M)):
        dp[b | tmp] += dp[b]



print(dp[-1])
