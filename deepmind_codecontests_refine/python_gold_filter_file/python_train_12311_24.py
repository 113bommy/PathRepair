t=int(input())
for i in range(t):
   a,b,c=map(int,input().split(" "))
   if b==1:
      if a<c:
         print(1,-1)
      elif a==c:
         print(-1,-1)
      else:
         print(-1,1)
   elif c<=a:
      print(-1,end=(" "))
      print(b)
   else:
      if a*b<=c:
         print(1,-1)
      else:
         print(1,end=(" "))
         sum=0
         t=0
         while sum<=c:
            sum+=a*b
            t+=b
         print(t)
         
   
         