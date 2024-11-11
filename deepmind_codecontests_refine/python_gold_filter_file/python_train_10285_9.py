import sys
sys.setrecursionlimit(10**9)

reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

mod = 10**9+7

n = int(input())
G = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a,b = a-1,b-1
    G[a].append(b)
    G[b].append(a)

cnt = [0]*n
def dfs(cur, prev):
    tmp = 1
    for to in G[cur]:
        if to != prev:
            tmp += dfs(to, cur)
    cnt[cur] = tmp
    return tmp

dfs(0, -1)

power = [0]*(n)
powe2_n = pow(2, n, mod)
powe2_n = pow(powe2_n, mod-2, mod)
power[n-1] = powe2_n
for i in reversed(range(n-1)):
    powe2_n *= 2
    powe2_n %= mod
    power[i] = powe2_n
ans = 0
from collections import deque
que = deque()
que.append((0, -1))

while que:
    cur, prev = que.pop()
    if len(G[cur]) == 1:
        if prev == -1:
            que.append((G[cur][0], cur))
        continue

    prob = 1
    prob -= power[n-2]

    for to in G[cur]:
        if to == prev:
            bubun_cnt = n-cnt[cur]
        else:
            que.append((to, cur))
            bubun_cnt = cnt[to]
        tmp = 1-power[bubun_cnt-1]
        tmp *= power[n-1-bubun_cnt-1]
        prob -= tmp
    prob %= mod
    ans += power[0]*prob
    ans %= mod

print(ans)

