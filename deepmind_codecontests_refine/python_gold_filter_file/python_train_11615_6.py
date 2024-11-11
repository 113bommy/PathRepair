n=int(input())
x=list(input())
if int(x[3])>5: x[3]='3'
if n==12:
   if x[1]=='0':
      if x[0]=='0': x[1]='1'
   if x[0]!='1' and x[0]!='0':
      if x[1]=='0': x[0]='1'
      else: x[0]='0'
   if int(x[1])>2:
      if x[0]=='1': x[1]='0'
else:
   if x[0]=='2':
      if int(x[1])>3: x[0]='0'
   elif int(x[0])>2:
      x[0]='0'
print(''.join(x))