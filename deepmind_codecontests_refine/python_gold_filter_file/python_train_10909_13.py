N = int(input())
S = input()

ans = 0
for p in range(1000):
  s = '{:03}'.format(p)
  i = 0
  for j in range(N):
    if i < 3 and S[j] == s[i]:
      i += 1
  if i == 3:
    ans += 1
print(ans)
