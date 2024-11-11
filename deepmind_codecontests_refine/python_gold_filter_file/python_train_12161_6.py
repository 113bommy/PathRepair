N, M, C = map(int, input().split())
B = list(map(int, input().split()))
cnt = 0
for _ in range(N):
  A = list(map(int, input().split()))
  cnt += int(sum([A[i] * B[i] for i in range(M)], C) > 0)
print(cnt)
