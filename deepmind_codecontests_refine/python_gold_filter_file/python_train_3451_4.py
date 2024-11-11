x=int(input())
a=[]
c=0
if(x==1):
   print(0)
   exit()
while(True):
   l=len(bin(x)[2:])
   
   y=2**(l) -1
   #print('l',l,'x',x,'y',y)
   x^=y
   a.append(l)
   c+=1
   s=bin(x)[2:]
   if(len(s) == s.count('1') ):
      
      break
   c+=1
   x+=1
   s=bin(x)[2:]
   if(len(s) == s.count('1') ):
      
      break
   
   
   
   
print(c)
print(' '.join(str(i) for i in a))
