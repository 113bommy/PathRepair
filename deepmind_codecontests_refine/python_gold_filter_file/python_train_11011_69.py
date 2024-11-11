N, K = map(int, input().split())
A = list(map(int, input().split()))

for i in range(K):
    B = [0] * N
    for j in range(N):
        l = max(0,j-A[j])
        r = j+A[j]+1
        B[l] += 1
        if r < N:
            B[r] -= 1
    for j in range(1, N):
        B[j] += B[j-1]

    A = B

    if sum(A) == N**2:
        break

print(*A)