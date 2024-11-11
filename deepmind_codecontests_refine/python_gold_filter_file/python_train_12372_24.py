n = int(input())
dist = [list(map(int,input().split())) for i in range(n)]
use = [[True for i in range(n)] for j in range(n)]
ans = 0

for i in range(n):
    for j in range(n):
        for k in range(n):
            if dist[j][k] > dist[j][i] + dist[i][k]:
                print(-1)
                exit()
            elif j != i and j != k and i != k and dist[j][k] == dist[j][i] + dist[i][k]:
                use[j][k] = False

for i in range(n):
    for j in range(n):
        if use[i][j]:
            ans += dist[i][j]

print(ans//2)