p=print
b=0
for e in iter(input,'0 0'):
 if b:p()
 b=f=1;s,t=map(int,e.split())
 for y in range(s,t+1):
  if(y%4==0)*(y%100)or y%400==0:p(y);f=0
 f and p('NA')
