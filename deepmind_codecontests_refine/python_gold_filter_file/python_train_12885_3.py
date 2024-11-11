s=input()
t=input()
m=0
for i in range(len(s)):
  if s[i]!=t[i]:
    m+=1
print(m)