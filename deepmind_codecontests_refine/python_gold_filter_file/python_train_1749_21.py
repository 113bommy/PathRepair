N, K = map(int, input().split())
S = input()
count = 0
for i in range(1, N):
  if S[i] == S[i - 1]:
    count += 1
print(min(N - 1, count + K * 2))
