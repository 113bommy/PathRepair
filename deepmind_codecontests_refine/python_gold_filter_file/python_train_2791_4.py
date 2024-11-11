N, K = map(int, input().split())
H = list(map(int, input().split()))
C = [0]*N
for i in range(1, N):
  j = max(0, i-K)
  C[i] = min([c + abs(H[i]-h) for c, h in zip(C[j:i], H[j:i])])
print(C[N-1])