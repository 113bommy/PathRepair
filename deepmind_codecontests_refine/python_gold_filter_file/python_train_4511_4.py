for _ in range(int(input())):
   n=int(input())
   if n%2==0:
      for i in range(1,n+1,2):
         print(i+1,i,end=" ")
   else:
      print(3,1,2,end=" ")
      n-=3
      for i in range(4,n+4,2):
         print(i+1,i,end=" ")
   print()
