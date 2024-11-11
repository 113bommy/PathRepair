from math import ceil


n, x, y = map(int, input().split())
total = n*(y/100)
total = ceil(total)
print(max(0, total - x))

