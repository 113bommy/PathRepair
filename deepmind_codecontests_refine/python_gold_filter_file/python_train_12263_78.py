import math
n = int(input())
a = math.ceil(n/1.08)
b = math.floor(a*1.08)
print(a*(n == b) or ":(")