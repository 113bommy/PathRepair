s=input()
t="CODEFESTIVAL2016"
ret=0
for i in range(len(s)):
  if s[i] != t[i]:
    ret+=1
print(ret)