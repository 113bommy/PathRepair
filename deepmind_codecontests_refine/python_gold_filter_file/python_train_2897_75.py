N = int(input())
S = [''] * N
for i in range(N):
  S[i] = input()
cnt = 0
for a in range(N):
  for i in range(N):
    _i = (i - a) % N
    for j in range(i):
      if S[_i][j] != S[(j - a) % N][i]:
        break
    else:
      continue
    break
  else:
    cnt += N
print(cnt)