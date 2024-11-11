x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
n = int(input())
d = [[int(i) for i in input().split()] for j in range(n)]
count = 0
if x1 != x2:
    k = (y2 - y1) / (x2 - x1)
    b = (y1 * x2 - y2 * x1) / (x2 - x1)
    for i in range(n):
        if -1 * d[i][0] != d[i][1] * k:
            x3 = -1 * (d[i][1] * b + d[i][2]) / (d[i][0] + d[i][1] * k)
            y3 = k * x3 + b
            if max(x1, x2) >= x3 >= min(x1, x2) and max(y1, y2) >= y3 >= min(y1, y2):
                count += 1
else:
    a = 1
    b = 0
    c = -1 * x1
    for i in range(n):
        if d[i][1] != 0:
            x3 = x1
            y3 = -1 * (d[i][2] + d[i][0] * x1) / d[i][1]
            if max(x1, x2) >= x3 >= min(x1, x2) and max(y1, y2) >= y3 >= min(y1, y2):
                count += 1
print(count)