from itertools import accumulate

N, K, *A = map(int, open(0).read().split())

for _ in range(min(K, 41)):
    B = [0] * (N + 1)
    for x, d in enumerate(A):
        B[max(0, x - d)] += 1
        B[min(N, x + d + 1)] -= 1
    A = list(accumulate(B))

print(*A[:-1])