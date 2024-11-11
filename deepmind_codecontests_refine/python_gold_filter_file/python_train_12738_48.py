a=int(input())

if a%2==1:
   print(-1)

else:
   l=[i+1 for i in range(a)]
   
   s=str(l[1])+" "+str(l[0])
   for k in range(1,a//2):
      l[2*k],l[2*k+1]=l[2*k+1],l[2*k]
      s=s+" "+str(l[2*k])+" "+str(l[2*k+1])
   print(s)
