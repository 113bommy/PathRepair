H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()
B = [1, W, 1, H]
for i in range(N - 1, -1, -1):
  if T[i] == 'L': B[1] = min(B[1] + 1, W)
  if T[i] == 'R': B[0] = max(B[0] - 1, 1)
  if T[i] == 'U': B[3] = min(B[3] + 1, H)
  if T[i] == 'D': B[2] = max(B[2] - 1, 1)
  if S[i] == 'L': B[0] += 1
  if S[i] == 'R': B[1] -= 1
  if S[i] == 'U': B[2] += 1
  if S[i] == 'D': B[3] -= 1
  if B[1] < B[0] or B[3] < B[2]:
    print('NO')
    break
else:
  print('YES' if B[0] <= sc <= B[1] and B[2] <= sr <= B[3] else 'NO')