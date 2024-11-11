n=int(input())
k=0
c=0
for i in range(n):
  a,b=map(int,input().split())
  if(a==b):
      k+=1
      if(k>=3):
          c=1
  else:
      k=0

if(c==1):
  print("Yes")
else:
  print("No")
