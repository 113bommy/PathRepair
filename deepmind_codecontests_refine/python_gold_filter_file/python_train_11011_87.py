N, K = map(int, input().split())
A = [int(i) for i in input().split()]

for _ in range(K):
    S = [0] * (N + 1)
    for i, a in enumerate(A):
        l = min(N-1, max(0, i-a))
        r = min(N-1, i+a)
        S[l] += 1
        S[r+1] -= 1
    t = 0
    for i in range(N):
        t += S[i]
        A[i] = t
    if sum(A) == N**2:
        break
print(*A)