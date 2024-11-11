import math

t = int(input())
for i in range(t):
    n = int(input())
    res = 0
    for j in range(n):
        res += math.cos(math.radians(180 / n * j - 90))
    print(res)