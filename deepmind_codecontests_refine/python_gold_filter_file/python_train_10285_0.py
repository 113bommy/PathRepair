#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
MOD = 10**9 + 7

n = int(input())
edge = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = [int(item) - 1 for item in input().split()]
    edge[a].append(b)
    edge[b].append(a)

childs = [[] for _ in range(n)]
def dfs(p, v):
    val = 1
    for nv in edge[v]:
        if nv == p:
            continue
        ret = dfs(v, nv)
        val += ret
        childs[v].append(ret)
    if val != n:
        childs[v].append(n - val)
    return val

dfs(-1, 0)
total_pattern = pow(2, n, MOD)
total_pattern_inv = pow(total_pattern, MOD-2, MOD)
inv2 = pow(2, MOD-2, MOD)
pow2_table = [1]
for i in range(2 * 10**5):
    pow2_table.append(pow2_table[-1] * 2 % MOD)
ans = 0
for line in childs:
    pattern_ok = 0
    if len(line) == 1:
        continue
    for item in line:
        pattern_ok += pow2_table[item] - 1
    pattern_ok += 1
    ans += (total_pattern * inv2 - pattern_ok) * total_pattern_inv
    ans %= MOD
print(ans)