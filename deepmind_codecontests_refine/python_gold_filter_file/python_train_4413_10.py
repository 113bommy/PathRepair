n=int(input())
l=[]
l.extend(map(int,input().split()))
a , b = (map(int,input().split()))
e=max(a,b)
f=min(a,b)
sum1=sum2=0
if a==b:
  print(0)
else:
  for i in range(f,e):
    sum1+=l[i-1]

  for i in range(e-1,len(l)):
    sum2+=l[i]
  if (f-1)>0:
      for i in range(0,f-1):
       sum2+=l[i]
  print(min(sum1,sum2))