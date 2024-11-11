
import heapq
from collections import defaultdict
from functools import lru_cache
from bisect import bisect_right
while True:
    N, M, C, S, G = map(int, input().split())
    if N == M == C == S == G == 0:  # 駅の数、路線の数10000、鉄道会社の数20、出発駅、目的地駅
        break
    #E = [[[] for _ in range(N + 1)] for _ in range(C + 1)]
    D = [[[float("inf")] * (N + 1) for _ in range(N + 1)] for _ in range(C + 1)]
    CE = [set() for _ in range(C+1)]
    for _ in range(M):
        x, y, d, c = map(int, input().split())  # d<=200
        D[c][x][y] = min(D[c][x][y], d)
        D[c][y][x] = min(D[c][x][y], d)
        CE[c].add(x)
        CE[c].add(y)

    P = list(map(int, input().split()))  # <= 50
    Q = []
    R = []
    for _ in range(C):
        Q.append(list(map(int, input().split())) + [1 << 30])
        R.append(list(map(int, input().split())))

    cum_fare = []
    for c_ in range(C):
        fare_ = [0]
        res = 0
        q_p = 0
        for q, r in zip(Q[c_][:-1], R[c_][:-1]):
            res += (q - q_p) * r
            q_p = q
            fare_.append(res)
        cum_fare.append(fare_)

    @lru_cache(maxsize=None)
    def fare(d_, c_):
        if d_==float("inf"):
            return float("inf")
        c_ -= 1
        idx = bisect_right(Q[c_], d_)
        #print(c_, idx, cum_fare[c_], R[c_])
        return cum_fare[c_][idx] + (R[c_][0] * d_ if idx==0 else (d_ - Q[c_][idx-1]) * R[c_][idx])


    DD = [[float("inf")] * (N + 1) for _ in range(N + 1)]
    for c in range(1, C + 1):
        D_ = D[c]
        l = list(CE[c])
        for k in l:
            for i in l:
                for j in l:
                    d_ = D_[i][k] + D_[k][j]
                    if D_[i][j] > d_:
                        D_[i][j] = d_
        # print(D_)
        for i in l:
            for j in l:
                DD[i][j] = min(DD[i][j], fare(D_[i][j], c))
    # print(DD)
    dist = defaultdict(lambda: float("inf"))
    q = []
    start = S
    dist[start] = 0
    heapq.heappush(q, (0, start))
    while len(q) != 0:
        prob_cost, v = heapq.heappop(q)
        # print(prob_cost, v)
        if dist[v] < prob_cost:
            continue
        if v == G:
            print(prob_cost)
            break
        for u, c in enumerate(DD[v]):
            if dist[u] > dist[v] + c:
                dist[u] = dist[v] + c
                heapq.heappush(q, (dist[u], u))
    else:
        print(-1)

