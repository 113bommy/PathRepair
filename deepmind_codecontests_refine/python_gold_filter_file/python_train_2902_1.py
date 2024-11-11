p=print
b=0
for e in iter(input,'0 0'):
 if b:p()
 b=u=1;s,t=map(int,e.split())
 for y in range(s,t+1):
  if((y%4==0)*(y%100!=0)or y%400==0):p(y);u=0
 if u:p('NA')
