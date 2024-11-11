import math
a,b,c,d = map(float, input().split())
t = pow(a-c,2) + pow(b-d,2)
print(math.sqrt(t))