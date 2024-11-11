t = int(input())
from math import ceil
while t > 0:
    n, m = map(int, input().split())
    print(ceil((n * m) / 2))
    t -= 1