import heapq
n,m = list(map(int,input().split()))
l = sorted([(int(a)*-1) for a in input().split()])
for i in range (m):
  high = heapq.heappop(l)
  heapq.heappush(l,-(-high//2))
print(abs(sum(l)))