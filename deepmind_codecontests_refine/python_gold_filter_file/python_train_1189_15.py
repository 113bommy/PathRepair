from collections import Counter,defaultdict

from math import factorial as fact


      

#t = int(input())


n,m = [int(x) for x in input().split()]
if n>m+1 or (m-2)/n>2:
   print(-1)
else:
   if n==m+1:
      print('01'*m+'0')
   elif n==m:
      print('01'*m)
   else:
      while m>n and n!=0:
         print('110',end='')
         m-=2
         n-=1
      ok = False
      while m!=n:
         ok = True
         print('1',end='')
         m-=1
      if ok:
         print('01'*m)
      else:
         print('10'*m)
      














