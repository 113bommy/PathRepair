import math
t=int(input())
for i in range(t):
 
  #n =list(map(int,input().split()))
  #s = ''.join(str(e) for e in n)
  n=int(input())
  s=input()
#print(s)
#t= len(s)
  x=s.count("10")
  y=s.count("01")
#print(x,y)
  tmp=n-x-y
  if tmp==1:
    print(0)
  elif n%2==0:
    print(tmp//2)
  else:
    print(math.ceil(tmp/2))    
