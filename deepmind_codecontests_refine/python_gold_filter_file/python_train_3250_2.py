t=int(input())
for i in range(t):
   a=input()
   b=len(a)
   n=int(a)
   if b==1:
      print(n)
   else:
      sum=(b-1)*9
      c=int("1"*b)
      i=1
      while c*i<=n:
         sum+=1
         i+=1
      print(sum)