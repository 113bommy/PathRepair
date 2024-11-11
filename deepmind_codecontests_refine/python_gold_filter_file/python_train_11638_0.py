N, K = map(int, input().split())
A = []
for _ in range(K):
  d = input()
  A += list(map(int, input().split()))
print(N - len(set(A)))