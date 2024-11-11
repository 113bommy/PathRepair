import sys
sys.setrecursionlimit(10**6)
from operator import mul
from functools import reduce

def comb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under


def dfs(v, cur):
    color[v] = cur
    
    for next_v in Graph[v]:
        if color[next_v] != -1:
            if color[next_v] != cur:
                continue
            else:
                return False
        elif not dfs(next_v, 1-cur):
            return False
    return True
        


N, M = map(int, input().split())
AB = [[int(_) for _ in input().split()] for _ in range(M)]
Graph = [[] for _ in range(N)]
color = [-1]*N

for i in AB:
    Graph[i[0]-1].append(i[1]-1)
    Graph[i[1]-1].append(i[0]-1)

if dfs(0, 0):
    black = color.count(0)
    white = N - black
    print(black*white-M)
else:
    print(comb(N, 2)-M)