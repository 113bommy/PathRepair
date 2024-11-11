N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
b = any(all(A[i+k][j+l]==B[k][l] for k in range(M) for l in range(M)) for i in range(N-M+1) for j in range(N-M+1))
print("YNeos"[not b::2])