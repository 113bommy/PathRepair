x=eval(input())
s=''
d=[]
if(x%4==0):
  s+=(x//4) * '4'
  d+=[(s)]
if(x%7==0):
  s=''
  s+=(x//7)*'7'
  d+=[(s)]
f=True
s=''
while(x>0 and f==True):
  x-=4
  s+='4'
  if(x%7==0):
    s+=(x//7) *'7'
    f=False
    d+=[(s)]
i=0
if(len(d)>=1):
  print(min(d, key=len))    
else:
  print(-1)
