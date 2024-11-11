import math
h = int(input())
w = int(input())
n = int(input())
h = max(h,w)
print(math.ceil(n/h))