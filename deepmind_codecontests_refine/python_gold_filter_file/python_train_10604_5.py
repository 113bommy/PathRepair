S = input()
T = 'CODEFESTIVAL2016'
ans = 0
for i in range(16):
  ans += S[i] != T[i]
print(ans)
  
