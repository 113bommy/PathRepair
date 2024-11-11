INF = 10**9
from heapq import heappop,heappush
H,W = (int(i) for i in input().split())
Ch,Cw = (int(i)-1 for i in input().split())
Dh,Dw = (int(i)-1 for i in input().split())
S = [input() for i in range(H)]

dist = [[INF]*W for _ in range(H)]
dist[Ch][Cw]= 0
que = [(0,Ch*W+Cw)]
while(que):
    u_dist,u = heappop(que)
    uh,uw = u//W,u%W
    #if dist[uh][uw] < u_dist:
    #    continue
    for dh in range(-2,3):
        for dw in range(-2,3):
            nh = uh + dh
            nw = uw + dw
            if nh<0 or H <= nh or nw < 0 or W <= nw:
                continue
            if S[nh][nw]=="#":
                continue
            cost = 0 if abs(dh)+abs(dw)<=1 else 1
            if dist[nh][nw] > dist[uh][uw] + cost:
                dist[nh][nw] = dist[uh][uw] + cost
                heappush(que,(dist[nh][nw],nh*W+nw))
if dist[Dh][Dw] == INF:
    print(-1)
else:
    print(dist[Dh][Dw])