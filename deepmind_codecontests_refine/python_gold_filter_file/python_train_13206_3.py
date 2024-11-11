S = input()
ans = 0
for i in range(1,len(S)):
  if S[i] != S[i-1]:
    ans += 1
print(ans)