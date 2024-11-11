import heapq

def argsort(seq):
    return sorted(range(len(seq)), key=seq.__getitem__)

n, k = map(int, input().split())
a = []
b = []
c  =[]
for i in range(n):
  x, y = map(int, input().split())
  a.append(x)
  b.append(y)
  c.append([x, y])


ind = argsort(b)
b = sorted(b)
b = b[::-1]
ind = ind[::-1]
na = []

for i in range(n):
  na.append(a[ind[i]])

a = na
ta = [a[0]]
sm = sum(ta)
mnd = b[0]
count = 1
p = 0

res = sm*mnd

queue = [a[0]]

for i in range(1, n):
  if count>=k:
    heapq.heappush(queue, a[i])
    sm = sm-heapq.heappop(queue)+a[i]
    mnd = b[i]
    res = max(res, sm*mnd)
  else:
    sm = sm+a[i]
    mnd = b[i]
    heapq.heappush(queue, a[i])
    count+=1
    res = max(res, sm*mnd)

print(res)