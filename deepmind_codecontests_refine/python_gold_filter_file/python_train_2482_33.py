import sys
s=input()
T=input()
a=[]
for i in range(len(s)-len(T)+1):
  for j in range(len(T)):
    if T[j]!=s[i+j] and "?"!= s[i+j] :
      break
  else:
    a.append(s[:i].replace('?', 'a')+T+s[i+len(T):].replace('?', 'a'))
 
if a==[]:
  print("UNRESTORABLE")
else:
  a.sort()
  print(a[0])