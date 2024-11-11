import math
n=int(input())
m=int(input())
x=[int(input()) for v in range(n)]
x_max=max(x)
x_sum=sum(x)
xx_min=math.ceil((x_sum+m)/n)
xx_min=max([xx_min,x_max])
xx_max=x_max+m
print(xx_min,xx_max)