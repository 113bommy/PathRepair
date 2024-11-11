import heapq as h
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
e6 = 10**6
q = [-b[i]*e6-i for i in range(n)]
h.heapify(q)
cnt = 0
while q:
  w = -h.heappop(q)
  v,i = w//e6, w%e6
  u = b[(i-1)%n] + b[(i+1)%n]
  if v < u or a[i] == v: continue
  elif a[i] > v: print(-1); exit(0)
  t = (v-a[i])//u
  if not t: print(-1); exit(0)
  cnt += t
  b[i] -= t*u
  if b[i] > a[i]:
    h.heappush(q,-b[i]*e6-i)
print(cnt if a==b else -1)