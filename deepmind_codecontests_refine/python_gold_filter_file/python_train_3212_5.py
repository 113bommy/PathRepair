N,M,Q = map(int,input().split())
src = [input() for i in range(N)]
qs = [tuple(map(int,input().split())) for i in range(Q)]

blue_cum = [[0 for j in range(M+1)] for i in range(N+1)]
for i in range(N):
    for j in range(M):
        blue_cum[i+1][j+1] += blue_cum[i+1][j] + int(src[i][j])
for i in range(N):
    for j in range(M+1):
        blue_cum[i+1][j] += blue_cum[i][j]

h_edge = [[0 for j in range(M)] for i in range(N+1)]
for i in range(N):
    for j in range(M-1):
        h_edge[i+1][j+1] += h_edge[i+1][j] + int(src[i][j:j+2]=='11')
for i in range(N):
    for j in range(M):
        h_edge[i+1][j] += h_edge[i][j]

v_edge = [[0 for j in range(M+1)] for i in range(N)]
for i in range(N-1):
    for j in range(M):
        v_edge[i+1][j+1] += v_edge[i+1][j] + int(src[i][j]=='1' and src[i+1][j]=='1')
for i in range(N-1):
    for j in range(M+1):
        v_edge[i+1][j] += v_edge[i][j]

ans = []
for y1,x1,y2,x2 in qs:
    y1 -= 1
    x1 -= 1
    blue = blue_cum[y1][x1] - blue_cum[y1][x2] - blue_cum[y2][x1] + blue_cum[y2][x2]
    edge = h_edge[y1][x1] - h_edge[y1][x2-1] - h_edge[y2][x1] + h_edge[y2][x2-1]
    edge+= v_edge[y1][x1] - v_edge[y1][x2] - v_edge[y2-1][x1] + v_edge[y2-1][x2]
    ans.append(blue - edge)
print(*ans, sep='\n')