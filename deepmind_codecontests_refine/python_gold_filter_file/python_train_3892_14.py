a=sorted(input())
b=0
while len(a)>1:
  if a[0]==a[1]:
    a=a[2:]
  else:
    a=a[1:]
    b+=1
if (b+len(a))%2==0 and b>0:
  print('Second')
else:
  print('First')