# from bisect import bisect_left
import heapq

TC = int(input())

for tc in range(TC):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    result = 0

    if A[-1] > K:
        print(0)
        continue

    if N > 2:
        max_n = A[0]
        for a in A[2:]:
            result += max((K - a) // max_n, 0)

    a = A[0]
    b = A[1]
    r1 = max((K - b) // a, 0)
    r2 = 0
    while b <= K:
        a, b = b, a + b
        r2 += 1

    print(result + max(r1, r2 - 1))
