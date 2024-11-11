#import sys
#import math
#sys.stdout=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/output.txt","w")
#sys.stdin=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/input.txt","r")
a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
ans=0
if (e>f):
   ans+=(e*min(a,d))
   d=d-min(a,d)
   min1=min(b,d)
   min2=min(c,d)
   mini=min(min1,min2)
   ans+=(f*mini)
else:
   l=[]
   l.append(b)
   l.append(c)
   l.append(d)
   ans+=(f*min(l))
   d=d-min(l)
   
   ans+=(e*min(a,d))

print(ans)






   


   
   

