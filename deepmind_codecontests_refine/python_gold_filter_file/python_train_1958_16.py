#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S(): return list(sys.stdin.readline())[:-1]
def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

#A
def A():
    n,a,b = LI()
    print(min(a*n,b))
    return

#B
def B():
    n,d = LI()
    x = LIR(n)
    f = defaultdict(lambda : 0)
    for i in range(1000000):
        f[i*i] = 1
    ans = 0
    for i in range(n):
        for j in range(i+1,n):
            s = 0
            for k in range(d):
                s += (x[i][k]-x[j][k])**2
            if f[s]:
                ans += 1
    print(ans)
    return

#C
def C():
    l,r = LI()
    if r-l > 2019:
        print(0)
        quit()
    ans = float("inf")
    for i in range(l,r+1):
        for j in range(i+1,r+1):
            if i*j%2019 < ans:
                ans = i*j%2019
    print(ans)
    return

#D
def D():
    n = I()
    a = LI()
    for i in range(n):
        a[i] *= 2
    x = a[0]
    for i in range(1,n):
        if i%2:
            x -= a[i]
        else:
            x += a[i]
    b = [x//2]
    for i in range(n-1):
        b.append(abs(b[-1]-a[i]))
    print(*b)
    return

#E
def E():
    n,k = LI()
    v = [[] for i in range(n)]
    for i in range(n-1):
        a,b = LI()
        a -= 1
        b -= 1
        v[a].append(b)
        v[b].append(a)
    if k == 1:
        if n == 1:
            print(1)
            quit()
        else:
            print(0)
            quit()
    if k == 2:
        print(2)
        quit()
    d = [0]*n
    v.append([])
    v.append([])
    q = deque([0])
    bfs = [1]*n
    bfs[0] = 0
    f = [0]*n
    while q:
        x= q.popleft()
        for y in v[x]:
            if bfs[y]:
                bfs[y] = 0
                q.append(y)
    ans = 1
    q = deque([0])
    dp = [None]*n
    dp[0] = k
    bfs = [1]*n
    bfs[0] = 0
    while q:
        x = q.popleft()
        m = len(v[x])
        for y in v[x]:
            if bfs[y]:
                bfs[y] = 0
                dp[y] = k-m
                m -= 1
                q.append(y)
    for i in dp:
        ans *= i
        ans %= mod
    print(ans)
    return

#F
def F():
    def lca(x,y):
        k = depth[x]-depth[y]
        while k > 0:
            x = par[x][int(math.log(k,2))]
            k = depth[x]-depth[y]
        k = -k
        while k > 0:
            y = par[y][int(math.log(k,2))]
            k = depth[y]-depth[x]
        if x == y:
            return x
        for i in range(M+1)[::-1]:
            if par[x][i] != par[y][i]:
                x = par[x][i]
                y = par[y][i]
        return par[x][0]

    def euler_tour(x,check,color):
        for i,c,d,k in f[x]:
            if k:
                query[i] -= 2*(-color[c][0]+color[c][1]*d)
            else:
                query[i] += -color[c][0]+color[c][1]*d
        for y,c,d in v[x]:
            if not check[y]:
                check[y] = 1
                color[c][0] += d
                color[c][1] += 1
                euler_tour(y,check,color)
                check[y] = 0
                color[c][0] -= d
                color[c][1] -= 1

    M = 17 #2^17 >= 10^5
    n,Q = LI()
    v = [[] for i in range(n)]
    for i in range(n-1):
        a,b,c,d = LI()
        a -= 1
        b -= 1
        c -= 1
        v[a].append((b,c,d))
        v[b].append((a,c,d))
    par = [[] for i in range(n)]
    par[0].append(0)
    dist = [-1]*n
    dist[0] = 0
    depth = [0]*n
    q = deque([0])
    while q:
        x = q.popleft()
        for y,c,d in v[x]:
            if dist[y] < 0:
                dist[y] = dist[x]+d
                depth[y] = depth[x]+1
                q.append(y)
                par[y].append(x)

    l = [i for i in range(n)]
    l.sort(key = lambda x:depth[x])
    for i in range(M):
        for x in l:
            par[x].append(par[par[x][i]][i])
    f = [[] for i in range(n)] #各頂点にqueryの情報を持たせる ← すごい
    query = [0]*Q #オイラーツアー、LCAを用いた距離計算により各クエリの答えを計算
    for i in range(Q):
        x,y,a,b = LI()
        x -= 1
        a -= 1
        b -= 1
        f[a].append((i,x,y,0))
        f[b].append((i,x,y,0))
        l = lca(a,b)
        f[l].append((i,x,y,1))
        query[i] = dist[a]+dist[b]-2*dist[l]
    check = [0]*n
    check[0] = 1
    color = [[0,0] for i in range(n)] #色ごとにオイラーツアーでdist_sum(color),num(color)を計算(その色の距離,その色の数)
    euler_tour(0,check,color)
    for i in query:
        print(i)
    return


#Solve
if __name__ == "__main__":
    F()
