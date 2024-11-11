def solve():
    import sys
    input = sys.stdin.readline

    N, M, Q = map(int, input().split())
    Sss = [input().rstrip() for _ in range(N)]

    numVertexss = [[0]*(M+1)] + [[0] + list(map(int, Ss)) for Ss in Sss]
    numEdgeVss = [[0]*(M+1) for _ in range(N+1)]
    numEdgeHss = [[0]*(M+1) for _ in range(N+1)]
    for i in range(1, N):
        for j in range(1, M+1):
            if numVertexss[i][j] and numVertexss[i+1][j]:
                numEdgeVss[i][j] = 1
    for i in range(1, N+1):
        for j in range(1, M):
            if numVertexss[i][j] and numVertexss[i][j+1]:
                numEdgeHss[i][j] = 1

    def getAccAss(Ass):
        for x in range(1, N+1):
            for y in range(M+1):
                Ass[x][y] += Ass[x-1][y]
        for x in range(N+1):
            for y in range(1, M+1):
                Ass[x][y] += Ass[x][y-1]
    def getRangeSum2D(accAss, xFr, xTo, yFr, yTo):
        return accAss[xTo+1][yTo+1] - accAss[xTo+1][yFr] - accAss[xFr][yTo+1] + accAss[xFr][yFr]

    getAccAss(numVertexss)
    getAccAss(numEdgeVss)
    getAccAss(numEdgeHss)

    anss = []
    for _ in range(Q):
        x1, y1, x2, y2 = map(int, input().split())
        x1, y1, x2, y2 = x1-1, y1-1, x2-1, y2-1
        ans = getRangeSum2D(numVertexss, x1, x2, y1, y2)
        ans -= getRangeSum2D(numEdgeVss, x1, x2-1, y1, y2)
        ans -= getRangeSum2D(numEdgeHss, x1, x2, y1, y2-1)
        anss.append(ans)

    print('\n'.join(map(str, anss)))


solve()
