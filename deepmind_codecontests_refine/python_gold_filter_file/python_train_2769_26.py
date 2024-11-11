import math
l=[int(x) for x in input().strip().split(' ')]
a=l[0]
b=l[1]
m=min(a,b)
print(math.factorial(m))