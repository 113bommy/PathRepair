import math
a= int(input())
n= int(math.sqrt(2*a))
while n*(n+1)/2>a:
    n-=1
x= a-(n*(n+1)/2)
if x==0:
    print(n)
else:
    print(int(x))