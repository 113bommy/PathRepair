import sys
input = sys.stdin.buffer.readline
n, c = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(c)]
C = [list(map(int, input().split())) for _ in range(n)]
A = [[0]*c for _ in range(3)]
for i in range(n):
  for j in range(n):
    x = C[i][j] - 1
    r = (i+j)%3
    for y in range(c):
      A[r][y] += D[x][y]
ans = float("inf")
for i in range(c):
  for j in range(c):
    for k in range(c):
      if i == j or j == k or k == i:
        continue
      temp = A[0][i] + A[1][j] + A[2][k]
      ans = min(ans, temp)
print(ans)