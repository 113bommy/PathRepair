N,K = map(int, input().split())
H = list(map(int, input().split()))
L = [0]*N
for i in range (1,N):
  L[i] = min(L[i-j] + abs(H[i] - H[i-j]) for j in range(1, min(i,K)+1))
print(L[N-1])