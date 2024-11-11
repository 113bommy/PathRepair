from heapq import heapify, heappop, heappush

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

q = [(-val, i) for i, val in enumerate(b) if val != a[i]]
heapify(q)

# 3print(q)

cnt = 0

while q:
  bval, i = heappop(q)
  bval = - bval - a[i]
  dv, bval = divmod(bval, b[i - 1] + b[(i + 1) % n])
#   print(dv, bval,i)
  if dv == 0:
    print(-1)
    exit()
  bval += a[i]
  b[i] = bval
  cnt += dv
  if bval != a[i]:
    heappush(q, (- bval, i))
print(cnt)
