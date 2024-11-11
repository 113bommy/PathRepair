N = int(input())
S = input()

T = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
  for j in range(i + 1, N):
    if S[i] == S[j]:
      T[i][j] += T[i - 1][j - 1] + 1

answer = 0
for i in range(N):
  for j in range(N):
    if T[i][j] and j - i >= T[i][j]:
      answer = max(answer, T[i][j])
print(answer)