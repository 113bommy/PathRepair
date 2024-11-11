def gg(a,b):
    while a*b!=0:
        if a>b:
            a%=b
        else:
            b%=a
    return a+b
from math import *
l,r,x,y=map(int,input().split())
if y%x!=0:
    print(0)
else:
    k=0
    y//=x
    i=1
    while i<=sqrt(y) and i<=r:
        if y%i==0:
            a=i
            b=y//i
            if l<=a*x<=r and l<=b*x<=r:
                if gg(a,b)==1:
                    if a==b:
                        k+=1
                    else:
                        k+=2
        i+=1

                
    print(k) 
        
