K, Q = map(int, input().split())
D = [int(a) for a in input().split()]
for _ in range(Q):
    N, X, M = map(int, input().split())
    t = X%M
    for i in range(K):
        t += ((D[i]-1) % M + 1) * ((N-i-2) // K + 1)
    print(N - 1 - t//M)