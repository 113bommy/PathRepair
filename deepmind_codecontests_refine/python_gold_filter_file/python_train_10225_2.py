import collections
import heapq
n,m = map(int, input().split())

occupied = set(map(int, input().split()))

q = collections.deque(set([(1, x-1) for x in occupied if x-1 not in occupied] + \
                      [(1, x+1) for x in occupied if x+1 not in occupied]))
for _,x in q:
  occupied.add(x)
ans = []
tot = 0
while len(ans) < m:
  dist, x = q.popleft()
  tot += dist
  ans.append(x)
  if x-1 not in occupied:
    q.append((dist+1, x-1))
    occupied.add(x-1)
  if x+1 not in occupied:
    q.append((dist+1, x+1))
    occupied.add(x+1)
print(tot)
print(' '.join(map(str, ans)))
