import sys

f_i = sys.stdin

n = int(f_i.readline())

adj = [[]] * n
for x in f_i:
    x = list(map(int, x.split()))
    adj[x[0]] = [c_v for c_v in zip(x[3::2], x[2::2])]

import heapq

def dijkstra():
    PQ = [(0, 0)]
    isVisited = [False] * n
    distance = [999900001] * n

    distance[0] = 0
    
    while PQ:
        uc, u = heapq.heappop(PQ)

        if uc <= distance[u]:
            isVisited[u] = True
        
            for vc, v in adj[u]:
                if isVisited[v] == False:
                    t_cost = distance[u] + vc
                    if t_cost < distance[v]:
                        distance[v] = t_cost
                        heapq.heappush(PQ, (t_cost, v))

    for v, d in enumerate(distance):
        print(v, d)


dijkstra()