s=input()
t=input()
a=0
for x in range(len(s)):
  if s[x]!=t[x]:
    a+=1
print(a)