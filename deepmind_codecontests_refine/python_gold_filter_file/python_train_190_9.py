s=input()
sc=0
tc=0
for i in s:
  if i=='S':
    sc+=1
  elif sc!=0:
    sc-=1
  else :tc+=1
print(tc+sc)