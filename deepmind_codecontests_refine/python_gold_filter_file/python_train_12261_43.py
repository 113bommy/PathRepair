s=input()
c=0
mc=0
for i in s:
  if i=='R':
    c+=1
    mc=c
  else:
    c=0
print(max(c,mc))
