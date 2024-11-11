import sys
def I(): return int(sys.stdin.readline().rstrip())

K = I()

Graph = [0]*K
for i in range(K):
    if (i+1) % K != (10*i) % K:
        Graph[i] = [(1,(i+1) % K),(0,(10*i) % K)]  # 1を加える,10倍する
    else:
        Graph[i] = [(0,(10*i) % K)]

# dijkstra

from heapq import heappush,heappop

d = [100]*K
d[1] = 1
q = []
heappush(q,(1,1))
v = [False]*K
while q:
    a,n = heappop(q)
    if v[n]:
        continue
    v[n] = True
    for da,dn in Graph[n]:
        if v[dn]:
            continue
        if a+da < d[dn]:
            d[dn] = a+da
            heappush(q,(a+da,dn))

print(d[0])
