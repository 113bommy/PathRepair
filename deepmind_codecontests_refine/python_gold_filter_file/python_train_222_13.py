n=int(input())
s=input()
counter=0
for i in s:
    if(i=='1'):
      counter+=1
    else:
      counter-=1


if(counter!=0):
   print('1'+"\n"+ s)
else:
   print('2'+"\n"+ s[0:-1] + " " + s[-1])
