import sys
import copy
n = int(input())
dist = [list(map(int,input().split())) for _ in range(n)]
e = copy.deepcopy(dist)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if dist[i][j]>dist[i][k] + dist[k][j]:
                print(-1)
                sys.exit()
            if i!=j and i!=k and j!=k and dist[i][j]==dist[i][k] + dist[k][j]:
                #print(i,j,k)
                e[i][j]=float("inf")

#[print(*dist[l]) for l in range(n)]
ans = 0
for i in range(n):
    for j in range(n):
        if e[i][j]!=float("inf"):
            ans += dist[i][j]
print(ans//2)

