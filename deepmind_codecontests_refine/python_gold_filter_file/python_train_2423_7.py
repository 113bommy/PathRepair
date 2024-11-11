import sys
import math
t=int(input().strip())
for a0 in range(t):
   n=int(input())
   l1=[int(i) for i in input().split()]
   m=[]
   for i in range(n):
       if(i%2!=0):
            m.append(l1[i])
            m.append(l1[i-1])
   #print(m)
   s=''
   for i in range(n):
       if(i%2==0):
           s+=str(-m[i])+' '
       else:
           s+=str(m[i])+' '
           
   print(s)
       
  
   