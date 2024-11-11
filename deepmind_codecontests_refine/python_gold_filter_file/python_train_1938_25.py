from math import sqrt

rd = list(map(int, input().strip().split()))
r = rd[0]
d = rd[1]
n = int(input().strip())
count = 0
for i in range(n):
    query = list(map(int, input().strip().split()))
    x = query[0]
    y = query[1]
    R = query[2]
    D = sqrt(x*x + y*y)
    if D >= (r - d) + R and D <= (r - R):
        count += 1
print(count)