N, K = map(int, input().split())
A = list(map(int, input().split()))

for _ in range(K):
    A_old = A
    A = [0] * (N)
    for idx_A, a in enumerate(A_old):
        A[max(0, idx_A-a)] += 1
        if idx_A+a+1 < N:
            A[idx_A+a+1] -= 1
    for idx_A in range(1, N):
        A[idx_A] += A[idx_A-1]
    if A_old == A:
        break
print(" ".join(map(str, A)))
