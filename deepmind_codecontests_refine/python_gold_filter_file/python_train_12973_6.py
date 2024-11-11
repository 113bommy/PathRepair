from math import sqrt
n=int(input())
a=(int(sqrt(n))+(n//int(sqrt(n))))*2
print(a if n%int(sqrt(n))==0 else a+2)