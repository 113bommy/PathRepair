import sys
n = int(input())
road = [0]*n
for i in range(n):
  road[i] = [int(x) for x in input().split()]

road_judge = [[True]*n for i in range(n)]
for k in range(n):
  for i in range(n):
    for j in range(n):
      if road[i][j] > road[i][k]+road[k][j]:
        print(-1)
        sys.exit()
      if road[i][j] == road[i][k]+road[k][j] and i != k and j != k:
        road_judge[i][j] = False
ans = 0
for i in range(n):
  for j in range(n):
    if road_judge[i][j]:
      ans += road[i][j]
print(ans//2)