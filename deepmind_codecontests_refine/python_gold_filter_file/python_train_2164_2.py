import heapq
import sys

def main():

    n,m,s = map(int,input().split())
    uvab = [list(map(int,input().split())) for _ in range(m)]
    cd = [list(map(int,input().split())) for _ in range(n)]

    edges = [[[] for _ in range(n)] for _ in range(2501)]

    for u,v,a,b in uvab:
        for i in range(a,2501):
            edges[i][u-1].append(((v-1, i-a), b))
            edges[i][v-1].append(((u-1, i-a), b))

    for i in range(n):
        c,d = cd[i]
        for j in range(2501):
            edges[j][i].append(((i, min(j+c, 2500)), d))

    def dijkstra(edges, c):
        hq = []
        d = [[10**20] * n for _ in range(c)]
        d[min(2500, s)][0] = 0
        heapq.heappush(hq, (0, (0, min(2500, s))))
        while hq:
            d1, p = heapq.heappop(hq)
            for p2, d2 in edges[p[1]][p[0]]:
                if d[p2[1]][p2[0]] == -1 or d[p2[1]][p2[0]] > d1 + d2:
                    d[p2[1]][p2[0]] = d1 + d2
                    heapq.heappush(hq, (d1+d2, p2))
        return d

    dis = dijkstra(edges, 2501)
    ans = [10**20]*n
    for i in range(2501):
        for j in range(n):
            ans[j] = min(ans[j], dis[i][j])

    for i in ans[1:]:
        print(i)

if __name__ == '__main__':
    main()
