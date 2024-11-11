n, m = map(int, input().split())
points = [1] * (m + 1)
for i in range(n):
    a, b = map(int, input().split())
    for k in range(a, b + 1):
        points[k] = 0
print(sum(points) - 1)
for i in range(1, m + 1):
    if points[i] > 0:
        print(i, end=" ")
