s = input()
x,ans = "CODEFESTIVAL2016",0
for i in range(16):
  if x[i]!=s[i]: ans += 1
print(ans)
