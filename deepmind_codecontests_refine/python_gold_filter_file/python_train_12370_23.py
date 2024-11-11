n,i,a=int(input()),0,0
while n:
  r=(-2)**i
  if (n-r)%(-2*r)==0:
    a+=10**i;n-=r
  i+=1
print(a)
    
