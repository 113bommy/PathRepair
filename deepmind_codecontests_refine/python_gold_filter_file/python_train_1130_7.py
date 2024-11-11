import bisect
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int,input().split()))
d = int(input())
graph = [[0 for i in range(n+1)] for j in range(18)]
for i in range(n):
  x = bisect.bisect_right(a,a[i]+d)
  graph[0][i+1] = x
for j in range(1,18):
  for i in range(n):
    t = graph[j-1][i+1]
    graph[j][i+1] = graph[j-1][t]
q = int(input())
for _ in range(q):
  x,y = map(int,input().split())
  x,y = min(x,y),max(x,y)
  ans = 0
  for j in range(18)[::-1]:
    if graph[j][x] < y:
      ans += 2**j
      x = graph[j][x]
    if j == 0 and x < y:
      ans += 1
  print(ans)