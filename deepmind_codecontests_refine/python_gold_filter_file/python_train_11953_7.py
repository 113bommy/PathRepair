n=int(input())
l=[input(),input(),input()]
c=0
for x in zip(*l):
  if len(set(x))==3:
    c+=2
  elif len(set(x))==2:
    c+=1
print(c)