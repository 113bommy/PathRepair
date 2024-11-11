import math

n, k = [int(x) for x in input().split(' ')]
points = []
t = 0
for i in range(n):
    points.append([int(x) for x in input().split(' ')])

for i in range(n - 1):
    t += math.sqrt((points[i][0] - points[i + 1][0]) ** 2 + (points[i][1] - points[i + 1][1]) ** 2)

print(k * t / 50)