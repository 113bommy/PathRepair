n, k = [int(value) for value in input().split()]

points = []

distance = 0

for i in range(n):
    x, y = input().split()
    points.append([int(x), int(y)])

for i in range(0, n-1):
    distance += ((points[i+1][0] - points[i][0])**2 +
                 (points[i+1][1] - points[i][1])**2)**0.5

print(distance * k / 50)
