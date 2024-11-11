N = int(input())
S = list(input())

ans = S.count('R')*S.count('G')*S.count('B')

for i in range(N):
  for j in range(i+1, N):
    k = j + j - i
    if k < N :
      if (S[i] != S[j]) and (S[j] != S[k]) and (S[k] != S[i]) :
        ans -= 1

print(ans)