import math
a=int(input())
ans=0
for i in range(1,int(math.sqrt(a)),1):
  if a%i==0 and not i==1:
    cnt=0
    while a%i==0:
      cnt+=1
      a=a/i
    ans+=(math.sqrt(2*cnt+0.25)-0.5)//1
if not a==1:
  print(int(ans+1))
else:
  print(int(ans))