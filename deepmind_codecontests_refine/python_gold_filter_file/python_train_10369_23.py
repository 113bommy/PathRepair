import math

x, y, l, r = map(int, input().split())

n = int(math.log(r, min(x, y))) + 2

d = [0] * (n * n)

for i in range(n):
    for j in range(n):
        d[i * n + j] = x ** i + y ** j

d.sort()

# print(d)

i = 0

while d[i] < l:
    i += 1

answer = min(r + 1, d[i]) - l

while d[i + 1] <= r:
    answer = max(answer, d[i + 1] - d[i] - 1)
    i += 1

answer = max(answer, r - max(d[i], l - 1))
print(answer)
