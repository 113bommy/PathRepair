from itertools import accumulate
n, k, *A = map(int, open(0).read().split())
for _ in range(min(k, 50)):
    B = [0] * (n+1)
    for i in range(n):
        B[max(0, i-A[i])] += 1
        B[min(n, i+A[i]+1)] -= 1
    *A, = accumulate(B)
print(*A[:n])