from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

setrecursionlimit(1000000)
N,M = list(map(int,input().split()))

edges = [[] for _ in range(N)]

for i in range(M):
    L,R,D = list(map(int,input().split()))
    edges[L - 1].append((R -1,D))
    edges[R - 1].append((L-1, -D))


visited = [None] * N
place = [0] * N
inf = 10 ** 10


def walk(i):
    if visited[i]:
        return (place[i], place[i])
    visited[i] = True
    (n,m) = (inf, - inf)
    for j,d in edges[i]:
        #print(j,d)
        if visited[j] and place[j] != place[i] + d:
            print("No")
            exit()
        place[j] = place[i] + d
        (x,y) = walk(j)
        (n,m) = (min(n,x),max(m,y))
    return (n,m)


for i in range(N):
    if not visited[i]:
        place[i] = 0
    # 連結成分のminとmax
        (n,m) = walk(i)
        if m - n > 10 ** 9:
            print("No")
            exit()

print("Yes")