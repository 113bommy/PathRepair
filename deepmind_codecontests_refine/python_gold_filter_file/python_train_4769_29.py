from heapq import heappush, heappop
def inpl(): return list(map(int, input().split()))

Q = int(input())
L = []
R = []

B = 0
M = 0

for _ in range(Q):
    q = inpl()
    if len(q) == 3:
        B += q[2]
        if len(R) == 0:
            L.append(-q[1])
            R.append(q[1])
            continue

        M += min(abs(-L[0] - q[1]), abs(R[0] - q[1])) * (not (-L[0] <= q[1] <= R[0]))
        if q[1] < R[0]:
            heappush(L, -q[1])
            heappush(L, -q[1])
            heappush(R, -heappop(L))
        else:
            heappush(R, q[1])
            heappush(R, q[1])
            heappush(L, -heappop(R))
    else:
        print(-L[0], B+M)
