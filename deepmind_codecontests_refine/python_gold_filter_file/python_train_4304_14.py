x=int(input())
if(x==1):
   print(1)
elif(x==0):
   print(0)
else:
   u=1
   plus=0
   for i in range(x-1):
      plus+=2
      u+=6*plus
      
   print(u)