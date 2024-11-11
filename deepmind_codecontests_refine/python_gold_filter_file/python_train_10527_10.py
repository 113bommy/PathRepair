from math import *
n, k = map(int, input().split())
minx = k*n + 100000
for i in range(1, n+1):
    div = int(n/i)
    if div == n/i:
        x = k * div + i
        if n == floor(x/k)*(x%k) and floor(x/k) == div and (x%k) == i:
            minx = min(minx, x)
print(minx)