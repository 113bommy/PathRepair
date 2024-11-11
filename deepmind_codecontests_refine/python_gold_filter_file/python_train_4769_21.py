from heapq import *
import sys;input=sys.stdin.readline
Q, = map(int, input().split())
qs = []
c = 0
for i in range(Q):
    q = input().split()
    if len(q) == 1:
        c += 1
    else:
        a, b = int(q[1]), int(q[2])
        qs.append((a, b, c))
        c = 0
if c:
    qs.append((a, b, c))

R = [10**18]
L = [10**18]
ss = 0
for a, b, c in qs:
    xs = []
    if c:
        x = heappop(L)
        for _ in range(c):
            print(-x, ss)
        heappush(L, x)
    x = heappop(R)
    y = -heappop(L)
    if x < a:
        heappush(R, a)
        heappush(R, a)
        heappush(L, -x)
        heappush(L, -y)
        ss += a-x
    elif y > a:
        heappush(L, -a)
        heappush(L, -a)
        heappush(R, x)
        heappush(R, y)
        ss += y-a
    else:
        heappush(L, -a)
        heappush(R, a)
        heappush(L, -y)
        heappush(R, x)
    ss += b
