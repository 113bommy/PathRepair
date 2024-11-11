x=input()

x=list(x)
c=-1
if(len(x)<4):
    c=1
for i in range(0,len(x)):
   a=0
   for j in range(0,i):
       if(x[i]==x[j]):

           a+=1

   if(a==0):
       c+=1
print(c-3)