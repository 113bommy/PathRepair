import math
for i in range(int(input())):
       f,g=map(int,input().split())
       a=max(f,g)
       b=min(f,g)
       if math.gcd(a,b)==abs(a-b):
           print(abs(a-b),0)
           continue
       if a==b:
           print(0,0)
           continue
       if b==0:
           print(a-b,0)
           continue
       l=a-b
       m=a//l
       p=m*l
       u=(m+1)*(l)
       if a-p<u-a:
           print(a-b,a-p)
       else:
           print(a-b,u-a)


