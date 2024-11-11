import heapq

h, w = map(int, input().split())
i0, j0 = map(lambda x: int(x) - 1, input().split())
i1, j1 = map(lambda x: int(x) - 1, input().split())
S = [input() for i in range(h)]
inf = 10**10
D = [[inf] * w for i in range(h)]
D[i0][j0] = 0
Q = [(0, (i0, j0))]
heapq.heapify(Q)
while Q:
    _, (i, j) = heapq.heappop(Q)
    for di in range(-2, 3):
        for dj in range(-2, 3):
            ii, jj = i + di, j + dj
            if 0 <= ii < h and 0 <= jj < w and S[ii][jj] == ".":
                nex = int(abs(di) + abs(dj) != 1)
                if D[i][j] + nex < D[ii][jj]:
                    D[ii][jj] = D[i][j] + nex
                    heapq.heappush(Q, (D[ii][jj], (ii, jj)))
if D[i1][j1] >= inf:
    print(-1)
else:
    print(D[i1][j1])
