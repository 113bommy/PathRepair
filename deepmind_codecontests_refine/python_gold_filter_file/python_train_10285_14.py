def JOI14_B():
    N = I()
    A = [I()for _ in range(N)]
    A.extend(A)
    dp = [[0]*(N*2+1) for _ in range(N*2+1)]

    for j in range(N):
        for i in range(N*2-j):
            if (N-j)%2==1:
                dp[i][i+j] = max(dp[i+1][i+j]+A[i],dp[i][i+j-1]+A[i+j])
            else:
                if A[i]>A[i+j]:
                    dp[i][i+j] = dp[i+1][i+j]
                else:
                    dp[i][i+j] = dp[i][i+j-1]
    ans = 0
    for i in range(N):
        ans = max(ans,dp[i][i+N-1])
    print(ans)
    #print(dp)
    return

def square869120Contest1_G():
    def held_karp(dists,TL):
        # Copyright (c) 2016 Carl Ekerot
        """
        Implementation of Held-Karp, an algorithm that solves the Traveling
        Salesman Problem using dynamic programming with memoization.
        Parameters:
            dists: distance matrix
        Returns:
            A tuple, (cost, path).
        """
        n = len(dists)

        # Maps each subset of the nodes to the cost to reach that subset, as well
        # as what node it passed before reaching this subset.
        # Node subsets are represented as set bits.
        C = {}
        dp = defaultdict(int)

        # Set transition cost from initial state
        for k in range(1, n):
            C[(1 << k, k)] = (dists[0][k], 0)
            dp[(1 << k, k)] = 1

        # Iterate subsets of increasing length and store intermediate results
        # in classic dynamic programming manner
        for subset_size in range(2, n):
            for subset in itertools.combinations(range(1, n), subset_size):
                # Set bits for all nodes in this subset
                bits = 0
                for bit in subset:
                    bits |= 1 << bit
                shortest_length = inf
                # Find the lowest cost to get to this subset
                for k in subset:
                    prev = bits & ~(1 << k)

                    res = []
                    for m in subset:
                        if not (prev, m) in C:
                            continue
                        if m == 0 or m == k:
                            continue
                        if C[(prev, m)][0] + dists[m][k]>TL[m][k]:
                            continue
                        res.append((C[(prev, m)][0] + dists[m][k], m))
                        if shortest_length>C[(prev, m)][0] + dists[m][k]:
                            shortest_length = C[(prev, m)][0] + dists[m][k]
                    if not res:
                        continue
                    C[(bits, k)] = min(res)
                    for d,m in res:
                        if shortest_length!=d:
                            continue
                        dp[(bits, k)] += dp[(prev,m)]

        # We're interested in all bits but the least significant (the start state)
        bits = (2 ** n - 1) - 1

        # Calculate optimal cost
        res = []
        shortest_length = inf
        for k in range(1, n):
            if not (bits, k) in C:
                continue
            if C[(bits, k)][0] + dists[k][0] > TL[k][0]:
                continue
            res.append((C[(bits, k)][0] + dists[k][0], k))
            if shortest_length > C[(bits, k)][0] + dists[k][0]:
                shortest_length = C[(bits, k)][0] + dists[k][0]
        if not res:
            return False
        opt, parent = min(res)
        way = 0
        for d, k in res:
            if not (bits, k) in C:
                continue
            if C[(bits, k)][0] + dists[k][0] > TL[k][0]:
                continue
            if shortest_length < d:
                continue
            way += dp[(bits,k)]

        # Backtrack to find full path
        path = []
        for i in range(n - 1):
            path.append(parent)
            new_bits = bits & ~(1 << parent)
            _, parent = C[(bits, parent)]
            bits = new_bits

        # Add implicit start state
        path.append(0)

        return shortest_length, list(reversed(path)), way

    N, M = LI()
    dist = [[inf]*N for _ in range(N)]
    TL = [[0]*N for _ in range(N)]
    for _ in range(M):
        s, t, d, time = LI()
        s -= 1; t -= 1
        dist[s][t] = dist[t][s] = d
        TL[s][t] = TL[t][s] = time
    ans = held_karp(dist,TL)
    if (not ans) or ans[2]==0:
        print("IMPOSSIBLE")
        return
    print(ans[0],ans[2])
    return

def JOI13_D():
    def solve(yday,leader,next):
        a = [0]*3
        for i in range(3):
            if next&(1<<i)==(1<<i):
                a[i] = 1
        rep = 0
        if a[leader]==0:
            return rep
        for i in range(3):
            if yday&(1<<i)==(1<<i):
                if a[i]==1:
                    rep = 1
        return rep
    N = I()
    S = SI()
    member = {"J":0,"O":1,"I":2}
    dp = [[0]*8 for _ in range(N+1)]
    dp[0][1] = 1
    for i in range(N):
        leader = member[S[i]]
        for j in range(8):
            for k in range(8):
                dp[i+1][j] += (dp[i][k]*solve(k,leader,j))
    ans = sum(dp[-1])%10007
    #print(dp)
    print(ans)
    return

def JOI16_D():
    N, M = LI()
    A = [(I()-1)for _ in range(N)]
    imos = [[0] * (N + 1) for _ in range(M)]
    for i in range(M):
        for j in range(N):
            imos[i][j + 1] += imos[i][j] + (A[j] != i)
    loop = 2**M
    dp = [inf]*loop
    dp[0] = 0
    cnt = Counter(A)
    L = [0]*loop
    #print(imos)
    for i in range(loop):
        for j in range(M):
            if i&(1<<j)==(1<<j):
                continue
            next = i|(1<<j)
            if L[next]==0:
                L[next] = L[i]+cnt[j]
            cur = imos[j][L[next]] - imos[j][L[i]]
            if dp[next]>dp[i] + cur:
                dp[next] = dp[i] + cur
    ans = dp[-1]
    #print(L)
    print(ans)
    return

def ABC6_D():
    N = I()
    C = [I() for _ in range(N)]
    LIS = [C[0]]
    for i in range(N):
        if C[i] > LIS[-1]:
            LIS.append(C[i])
        else:
            LIS[bisect.bisect_left(LIS, C[i])] = C[i]
    print(N - len(LIS))
    return

def ABC134_E():
    N = I()
    A = [I()for _ in range(N)]
    que = deque()
    que.append(A[0])
    L = 1
    for i in range(1,N):
        cur = bisect.bisect_left(que,A[i])
        #print(que,cur,L)
        if cur==0:
            que.appendleft(A[i])
            L += 1
        else:
            que[cur-1] = A[i]

    #print(que)
    ans = len(que)
    print(ans)

    return

def JOI7_F():
    def dijkstra_2(edge_adj, node, start):
        # node<=2000くらい
        # edge_adj[node][to] = [cost]
        dist = [inf] * node
        used = [False] * node
        dist[start] = 0
        while True:
            v = -1
            for i in range(node):
                if not used[i] and (v == -1 or dist[v] > dist[i]):
                    v = i
            if v == -1:
                break
            used[v] = True
            for i in range(node):
                if dist[i] > dist[v] + edge_adj[v][i]:
                    dist[i] = dist[v] + edge_adj[v][i]
        return dist
    N, K = LI()
    V = [[inf]*N for _ in range(N)]
    ans = []
    for _ in range(K):
        A = LI()
        s = A[1]-1
        t = A[2]-1
        if A[0]==1:
            if V[s][t] <= A[3]:
                continue
            V[s][t] = A[3]
            V[t][s] = A[3]
        else:
            dist = dijkstra_2(V,N,s)
            ans.append(dist[t])
    for v in ans:
        if v==inf:
            print(-1)
            continue
        print(v)
    return

def JOI15_E():
    def bfs(n, E, fordfs):
        # 点の数、スタートの点、有向グラフ
        W = [inf] * n
        # 各点の状態量、最短距離とか,見たかどうかとか
        que = deque()
        for e in E:
            e -=1
            W[e] = 0
            que.append(e)
        while que:
            now = que.popleft()
            nowW = W[now]
            for ne in fordfs[now]:
                if W[ne] > nowW + 1:
                    W[ne] = nowW + 1
                    que.append(ne)
        return W

    class Dijkstra(object):
        """
        construct: O(ElogV)
        """

        def __init__(self, edges, start=0):
            """
            :param list of list of list of int edges:
            :param int start=0:
            """
            self.__dist = [inf] * len(edges)
            self.__dist[start] = 0
            self.__calculate(edges, start)

        @property
        def dist(self):
            return self.__dist

        def __calculate(self, edges, start):
            Q = [(0, start)]  # (dist,vertex)
            while (Q):
                dist, v = heapq.heappop(Q)
                if self.dist[v] < dist: continue  # 候補として挙がったd,vだが、他に短いのがある
                for u, cost in edges[v]:
                    if self.dist[u] > self.dist[v] + cost:
                        self.__dist[u] = self.dist[v] + cost
                        heapq.heappush(Q, (self.dist[u], u))
    N, M, K, S = LI()
    P, Q = LI()
    C = [I()for _ in range(K)]
    V = [[]for _ in range(N)]
    for _ in range(M):
        s, t = LI()
        s -= 1
        t -= 1
        V[s].append(t)
        V[t].append(s)
    L = bfs(N,C,V)
    #print(L)
    cost = [[]for _ in range(N)]
    for i in range(N):
        for v in V[i]:
            if L[v]==0:
                continue
            elif L[v]<=S:
                cost[i].append((v,Q))
            else:
                cost[i].append((v,P))
    di = Dijkstra(cost)
    ans = di.dist
    #print(cost)
    if L[-1]<=S:
        print(ans[N-1]-Q)
    else:
        print(ans[N-1]-P)
    return

def JOI13_E():
    def bfs(n, e, fordfs):
        # 点の数、スタートの点、有向グラフ
        W = [inf] * n
        # 各点の状態量、最短距離とか,見たかどうかとか
        W[e] = 0
        que = deque()
        que.append(e)
        while que:
            now = que.popleft()
            nowW = W[now]
            for ne in fordfs[now]:
                if W[ne] == inf:
                    W[ne] = nowW + 1
                    que.append(ne)
        return W

    def dijkstra_2(edge_adj, node, start):
        # node<=2000くらい
        # edge_adj[node][to] = [cost]
        dist = [inf] * node
        used = [False] * node
        dist[start] = 0
        while True:
            v = -1
            for i in range(node):
                if not used[i] and (v == -1 or dist[v] > dist[i]):
                    v = i
            if v == -1:
                break
            used[v] = True
            for i in range(node):
                if dist[i] > dist[v] + edge_adj[v][i]:
                    dist[i] = dist[v] + edge_adj[v][i]
        return dist
    N, K = LI()
    C = [[]for _ in range(N)]
    V = [[]for _ in range(N)]
    for i in range(N):
        C[i] = LI()
    for i in range(K):
        a, b = LI()
        a -= 1
        b -= 1
        V[a].append(b)
        V[b].append(a)
    costV = [[inf]*N for _ in range(N)]
    for i in range(N):
        L = bfs(N,i,V)
        c = C[i][0]; l = C[i][1]
        for j in range(N):
            if i==j:
                continue
            if L[j]<=l:
                costV[i][j] = c
    dist = dijkstra_2(costV,N,0)
    ans = dist[N-1]
    #print(costV)
    print(ans)
    return

def ABC12_D():
    def warshall_floyd(n, d):
        # d[i][j]: iからjへの最短距離
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        return d
    N, M = LI()
    V = [[inf]*N for _ in range(N)]
    for i in range(N):
        V[i][i] = 0
    for _ in range(M):
        a, b, t = LI()
        a -= 1
        b -= 1
        V[a][b] = t
        V[b][a] = t
    L = warshall_floyd(N,V)
    #print(L)
    ans = inf
    for i in range(N):
        cur = max(L[i])
        ans = min(ans,cur)
    print(ans)
    return

def ABC79_D():
    def warshall_floyd(n, d):
        # d[i][j]: iからjへの最短距離
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        return d
    H, W = LI()
    C = [LI()for _ in range(10)]
    A = [LI()for _ in range(H)]
    L = warshall_floyd(10,C)
    #print(L)
    ans = 0
    for a in A:
        for i in a:
            if i>=0:
                ans += L[i][1]
    print(ans)
    return

def JOIgassyuku10_3():
    N, M, K = LI()
    V = [[]for _ in range(N)]
    for _ in range(M):
        a, b, c = LI()
        a -= 1
        b -= 1
        V[a].append((b,c))
        V[b].append((a,c))


    return

def ABC74_D():
    def warshall_floyd(n, d):
        # d[i][j]: iからjへの最短距離
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        return d
    N = I()
    A = [LI() for _ in range(N)]
    dist = warshall_floyd(N,copy.deepcopy(A))
    shortest_path = 0
    for i in range(N):
        for j in range(N):
            if i==j:
                continue
            if dist[i][j]<A[i][j]:
                print(-1)
                return
            if dist[i][j]>A[i][j]:
                continue
            flag = True
            for k in range(N):
                if i==k or j==k:
                    continue
                judge = (dist[i][k]+dist[k][j])-dist[i][j]
                if judge==0:
                    flag = False
            if flag:
                shortest_path += A[i][j]
    ans = shortest_path//2
    print(ans)
    return

def ABC65_D():
    class Kruskal_UnionFind():
        # 無向グラフであるという前提に注意
        def __init__(self, N):
            self.edges = []
            self.rank = [0] * N
            self.par = [i for i in range(N)]
            self.counter = [1] * N

        def add(self, u, v, d):
            """
            u = from, v = to, d = cost
            """
            self.edges.append([u, v, d])

        def find(self, x):
            if self.par[x] == x:
                return x
            else:
                self.par[x] = self.find(self.par[x])
                return self.par[x]

        def unite(self, x, y):
            x = self.find(x)
            y = self.find(y)
            if x != y:
                z = self.counter[x] + self.counter[y]
                self.counter[x], self.counter[y] = z, z
            if self.rank[x] < self.rank[y]:
                self.par[x] = y
            else:
                self.par[y] = x
                if self.rank[x] == self.rank[y]:
                    self.rank[x] += 1

        def size(self, x):
            x = self.find(x)
            return self.counter[x]

        def same(self, x, y):
            return self.find(x) == self.find(y)

        def Kruskal(self):
            """
            return: 最小全域木のコストの和
            """
            edges = sorted(self.edges, key=lambda x: x[2])  # costでself.edgesをソートする
            res = 0
            for e in edges:
                if not self.same(e[0], e[1]):
                    self.unite(e[0], e[1])
                    res += e[2]
            return res
    N = I()
    X = []
    for i in range(N):
        a, b = LI()
        X.append((a,b))
    P = defaultdict(set)
    for i,x in enumerate(X):
        P[x] = i
    graph = Kruskal_UnionFind(N + 1)

    X.sort(key=lambda x:x[0])
    for i in range(N-1):
        if X[i+1][0]-X[i][0]>abs(X[i+1][1]-X[i][1]):
            continue
        r = X[i+1][0]-X[i][0]
        graph.add(P[X[i]], P[X[i+1]], r)

    X.sort(key=lambda x:x[1])
    for i in range(N-1):
        if X[i+1][1]-X[i][1]>abs(X[i+1][0]-X[i][0]):
            continue
        r = X[i+1][1]-X[i][1]
        graph.add(P[X[i]], P[X[i+1]], r)

    ans = graph.Kruskal()
    print(ans)
    return

def ABC84_D():
    def is_prime(n):
        if n == 1: return False
        for k in range(2, int(math.sqrt(n)) + 1):
            if n % k == 0:
                return False
        return True

    def like_2017(x):
        if is_prime(x) and is_prime(x//2+1):
            return True
        return False

    Q = I()
    maxX = 10**5
    imos = [0]*(maxX+1)
    for i in range(maxX+1):
        if like_2017(i) and i!=2:
            imos[i] = imos[i-1] + 1
        else:
            imos[i] = imos[i - 1]
    L = [LI()for _ in range(Q)]
    ans = []
    for l,r in L:
        cur = imos[r]-imos[l-1]
        ans.append(cur)
    for v in ans:
        print(v)
    return

def ABC34_C():
    # rが小さい時
    def cmb(n, r, mod):
        cur = 1
        for i in range(r):
            cur *= (n-i)
            cur %= mod
        for i in range(r):
            cur *= pow(i+1,mod-2,mod)
            cur %= mod
        return cur

    W, H = LI()
    r = W+H-2; l = H-1
    ans = cmb(r,l,mod)
    print(ans)
    return

def ABC145_D():
    def cmb(n, r, mod):
        cur = 1
        for i in range(r):
            cur *= (n-i)
            cur %= mod
        for i in range(r):
            cur *= pow(i+1,mod-2,mod)
            cur %= mod
        return cur

    X, Y = LI()
    if (X+Y)%3!=0:
        print(0)
        return
    r = (X+Y)//3; l = X-(X+Y)//3
    if l<0:
        print(0)
        return
    ans = cmb(r,l,mod)
    print(ans)
    return

def ABC21_D():
    def cmb(n, r, mod):
        cur = 1
        for i in range(r):
            cur *= (n-i)
            cur %= mod
        for i in range(r):
            cur *= pow(i+1,mod-2,mod)
            cur %= mod
        return cur

    N = I()
    K = I()
    r = N+K-1; l = K
    ans = cmb(r,l,mod)
    print(ans)
    return

def ABC149_F():
    # 子の数のカウント
    def dfs(n,s,edges,children):
        cur = 1
        children[s] = 0
        for i in edges[s]:
            if children[i]!=-1:
                continue
            children[i] = True
            now,children = dfs(n,i,edges,children)
            cur += now
        children[s] = cur
        return cur,children
    N = I()
    V = [[]for _ in range(N)]
    for _ in range(N-1):
        a, b = LI()
        a -= 1; b -= 1
        V[a].append(b)
        V[b].append(a)
    children = [-1]*N
    C = dfs(N,0,V,children)[1]
    #print(C)

    # 分母分子計算
    inv = pow(2, mod - 2, mod)
    ans = (1 - pow(inv, N, mod) - N * inv) % mod
    p = [pow(inv, i, mod) for i in range(N)]
    for i in range(1,N):
        c = C[i]
        d = N-c
        cur = (p[c]-1)*(p[d]-1)
        ans += cur
        ans %= mod
    print(ans)
    return


def square869120Contest1_E():
    N, Q = LI()
    A = LI()
    C = LI()
    C.append(1)
    L = [0]*N
    for i in range(1,N):
        L[i] = pow(A[i-1],A[i],mod) + L[i-1]
    #print(L)
    ans = 0
    now = 0
    for i in range(Q+1):
        next = C[i]-1
        cur = abs(L[next]-L[now])
        ans += cur
        ans %= mod
        now = next
        #print(ans)
    print(ans)
    return

import sys,copy,bisect,itertools,heapq,math,random
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque

import gc
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
_ep = 10**(-12)
alphabet = [chr(ord('a') + i) for i in range(26)]

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    ABC149_F()
"""
"""
