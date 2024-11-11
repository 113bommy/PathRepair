n = int(input())
points = [int(x) for x in input().split(" ")]
points.sort()
min = 99999999999999999999999
count = 0
for i in range(len(points) - 1):
    distance = abs(points[i+1] - points[i])
    if distance < min:
        min = distance
        count = 1
    elif min == distance:
        count += 1

print("{0} {1}".format(min, count))
