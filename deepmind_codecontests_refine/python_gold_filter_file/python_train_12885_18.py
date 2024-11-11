s=input()
t=input()
l=0
for i in range(len(s)):
  if s[i]!=t[i]:
    l+=1
print(l)