# -*- coding: utf-8 -*-

import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

S = input()
N = len(S)

# nxt[i][c] := i文字目以降で最初に文字cが登場するindex(存在しないときはN)
nxt = list2d(N+1, 26, N)
for i in range(N-1, -1, -1):
    for c in range(26):
        nxt[i][c] = nxt[i+1][c]
    c = ord(S[i]) - 97
    nxt[i][c] = i

# dp[i] := i文字目以降について「部分文字列とならない」最短の文字列長
dp = [INF] * (N+1)
# rest[i][(c, j)] := 位置iから見て、最小達成に用いた文字cと、次に使う文字のindexj
rest = [None] * (N+1)
dp[N] = 1
# 常に自分より後ろでの最小が必要になるので、後ろから埋めていく
for i in range(N-1, -1, -1):
    # iから見て先頭として使う文字を26通り全部試す
    # abcを昇順で回して、最小更新条件を等号なしにすることで、辞書順で小さい方を優先できる
    for c in range(26):
        # 次の文字がない時
        if nxt[i][c] == N:
            if dp[i] > 1:
                dp[i] = 1
                rest[i] = (c, N)
        # 次の文字がある時
        else:
            # i以降に文字cが出現するindex+1の位置での最短文字列長 + 1
            # 例えばaについてなら、a****となるので、****での最小とaの分で+1
            if dp[i] > dp[nxt[i][c]+1] + 1:
                dp[i] = dp[nxt[i][c]+1] + 1
                rest[i] = (c, nxt[i][c]+1)

# 復元
i = 0
ans = []
while i < N:
    c, idx = rest[i]
    ans.append(chr(c+97))
    i = idx
print(''.join(ans))
