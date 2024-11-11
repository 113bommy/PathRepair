import sys
input = sys.stdin.readline
N, M = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(N)]
for i in range(N):
  for j in range(M):
    if (i + j) % 2: a[i][j] = 720720
    else: a[i][j] = 720720 - a[i][j] ** 4
  print(*a[i])
