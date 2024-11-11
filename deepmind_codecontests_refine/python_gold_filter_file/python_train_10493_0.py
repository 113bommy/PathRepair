import math
a,b,x = map(int,input().split())
v = a*a*b
if 2*x <= v:
    ans = math.atan((a*b*b)/(2*x))
else:
    ans = math.atan((2*(v-x)/(a*a))/a)
print(math.degrees(ans))
