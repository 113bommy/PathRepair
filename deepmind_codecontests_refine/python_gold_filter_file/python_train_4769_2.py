import heapq
import sys

inp = sys.stdin.readline

Q = int(input())
B = 0

q, a, b = map(int, inp().split())
L, R = [-a], [a]
L_sum, R_sum = a, a
B = b

for i in range(Q - 1):
    q = list(map(int, inp().split()))
    if len(q) == 3:
        A = q[1]
        B += q[2]

        if A <= -L[0]:
            heapq.heappush(L, -A)
            M = -heapq.heappushpop(L, -A)
            heapq.heappush(R, M)

            L_sum += (2 * A - M)
            R_sum += M
        else:
            heapq.heappush(R, A)
            M = heapq.heappushpop(R, A)
            heapq.heappush(L, -M)

            R_sum += (2 * A - M)
            L_sum += M
    else:
        N = len(L)
        X = -L[0]
        print(X, (abs(L_sum - X * N) + abs(R_sum - X * N)) // 2 + B)
