input()
s=input()
a=c=0
for i in s:
  if i=='I':a+=1
  else:a-=1
  c=max(a,c)
print(c)