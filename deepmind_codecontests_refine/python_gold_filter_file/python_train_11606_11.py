n=int(input())
x=1
y=1
import math
if n==1:
    print(1)
else:
    for i in range(1,2*n-1):
        x=x*i
    for i in range(1,n):
        y=y*i
    print(int(x/(y**2)))
