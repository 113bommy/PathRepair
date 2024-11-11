# classを使うのをやめてlistで実施する
# dfsを再帰でなくstackを用いて書く
from collections import deque
import sys
input = sys.stdin.readline

def dfs():
    stk1 = deque([0])
    stk2 = deque([])
    while stk1:
        v = stk1.pop()
        visited[v] = True
        stk2.append(v)
        for i in range(len(AL[v][CHILDREN])):
            u = AL[v][CHILDREN][i]
            if visited[u]:
                AL[v][CHILDREN][i] = None
                continue
            stk1.append(u)

    for i in range(n - 1, -1, -1):
        v = stk2[i]
        for u in AL[v][CHILDREN]:
            if u is None:  continue
            AL[v][SIZE] += AL[u][SIZE]

def anaaki(v):
    ret = pow(2, n - 1, p) - 1
    for ch in AL[v][CHILDREN]:
        if ch is None: continue
        ret -= pow(2, AL[ch][SIZE], p) - 1
        ret %= p
    ret -= pow(2, n - AL[v][SIZE], p) - 1
    ret %= p
    return ret

n = int(input())
SIZE = 0
CHILDREN = 1
AL = [[1, []] for _ in range(n)]
visited = [False] * n
p = 10 ** 9 + 7

for i in range(n - 1):
    a, b = [int(x) - 1 for x in input().split()]
    AL[a][CHILDREN].append(b)
    AL[b][CHILDREN].append(a)

dfs()
numer = 0
for i in range(n):
    numer += anaaki(i)
    numer %= p

denom = pow(2, n, p)
print(numer * pow(denom, p - 2, p) % p)