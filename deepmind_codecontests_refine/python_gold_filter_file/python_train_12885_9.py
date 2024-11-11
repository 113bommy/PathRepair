s=input()
t=input()
n=0
for i in range(len(t)):
  if s[i]!=t[i]:
    n+=1
print(n)