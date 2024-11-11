N = int(input())
A = [int(x) for x in input().split()]
B = [0] * N
for i in range(N - 1, -1, -1):
  ai = A[i]
  for j in range(i, N, i + 1):
    ai ^= B[j]
  B[i] = ai
print(sum(B))
if sum(B):
  print(' '.join([str(i + 1) for i in range(N) if B[i]]))