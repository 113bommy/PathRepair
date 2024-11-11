import math
k=[int(x) for x in input().strip().split(' ')]
a=k[0]
b=k[1]
c=min(a,b)
print(math.factorial(c))