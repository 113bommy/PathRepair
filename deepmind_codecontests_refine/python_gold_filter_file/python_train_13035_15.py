from math import *
from bisect import *
from collections import Counter,defaultdict,deque
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
for _ in range(I()):
  d=defaultdict(bool)
  n,s,k=M()
  a=LI()
  for i in a:
    d[i]=True
  if not d[s]:print(0)
  else:
    ans=n
    for i in range(s-1,max(s-1001,0),-1):
      if d[i]!=True:ans=s-i;break
    for i in range(s+1,min(n+1,s+1001)):
      if d[i]!=True:ans=min(ans,i-s);break
    print(ans)














        
        
            


        



    









    

            







        
