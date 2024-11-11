s=input()
t=input()
p=0
for i in range(len(s)):
  if(s[i]!=t[i]):
    p+=1
print(p)