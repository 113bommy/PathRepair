from sys import exit
INF = 1<<32
V,E = [int(n) for n in input().split()]
s = [0]*E
t = [0]*E
d = [0]*E
dist = [[INF for _ in range(V)] for __ in range(V)]
for i in range(V):
    dist[i][i]= 0
for i in range(E):
    s[i], t[i], d[i] = [int(n) for n in input().split()]
    dist[s[i]][t[i]] = d[i]

for k in range(V):
    for i in range(V):
        if(dist[i][k]== INF):continue
        for j in range(V):
            if(dist[k][j]== INF):continue
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(V):
    if dist[i][i] < 0:
        print("NEGATIVE CYCLE")
        exit()

for i in range(V):
    for j in range(V):
        if j != V-1:
            print(dist[i][j] if dist[i][j] != INF else "INF",end=" ")
        else:
            print(dist[i][j] if dist[i][j] != INF else "INF")

# N = int(input())
# a = [int(input()) for _ in range(N)]
# S = str(input())
# L = len(S)
# T = str(input())
# exit()

