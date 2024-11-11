import math

r = 100
n = int(input())
for i in range(n):
    r = math.ceil(r * 1.05)
print(r * 1000)

