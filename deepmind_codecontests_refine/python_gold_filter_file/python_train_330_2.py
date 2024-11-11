t=int(input())
while(t):
 t-=1
 n=int(input())
 a=list(map(int,input().split()))
 if(n<=2):
  print(0,0,0)
  continue
 b=dict()
 for i in a:
  if(i not in b):
   b[i]=1
   continue
  b[i]+=1
 ma=n//2
 res=[0]*3
 z=0
 co=0
 for i in b.keys():
  if(co==0):
   res[0]=b[i]
   co+=1
   su=res[0]
  else:
   su+=b[i]
   if(su>ma):
    break
   res[co]+=b[i]
   if(res[co]>res[0]):
    if(co!=2):
     co+=1
 if(0 in res or res[0]>=res[1] or res[0]>=res[2]):
  print(0,0,0)
  continue
 print(*res)
  
