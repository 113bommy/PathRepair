N, S = map(int, input().split())
A = list(map(int,input().split()))

MOD = 998_244_353

D = [[0 for _ in range(S+1)] for _ in range(N+1)]
D[0][0] = 1
for i in range(1, N+1):
  for j in range(0, S+1):
    D[i][j] = 2 * D[i-1][j] % MOD
    if j >= A[i-1]:
      D[i][j] += D[i-1][j-A[i-1]]
      D[i][j] %= MOD
  #print(D[i])
    
print(D[N][S])