import math

a,b = map(int, input().split())

n = int(input())
min = 100000000

for i in range(n):
    x, y, v = map(int, input().split())
    x1 = math.fabs(x - a)
    y1 = math.fabs(y - b)
    dist = math.sqrt(x1 * x1 + y1 * y1)
    time = dist / v
    if time < min:
        min = time

print(min)