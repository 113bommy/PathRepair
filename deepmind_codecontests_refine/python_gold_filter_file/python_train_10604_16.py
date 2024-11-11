str = "CODEFESTIVAL2016"
s =input()
cnt = 0
for i in range(16):
  if s[i]!=str[i]:
    cnt+=1
print(cnt)