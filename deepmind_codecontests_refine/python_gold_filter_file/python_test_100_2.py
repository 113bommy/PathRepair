import heapq
for step in range(int(input())):
  n = int(input())
  heap = list(map(int,input().split()))
  heapq.heapify(heap)
  ans = -1e9-1
  res = 0
  for i in range(n):
    m = heapq.heappop(heap)
    ans = max(m-res,ans)
    res = m
  print(ans)