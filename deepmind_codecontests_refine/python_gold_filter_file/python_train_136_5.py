import math
a,b,c=tuple(map(int,input().split()))

t = math.ceil((a - b)*c/b)
print(t)