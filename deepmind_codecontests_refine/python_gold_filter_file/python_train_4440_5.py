from math import ceil
r, g, b = map(lambda x: ceil(int(x) / 2) * 3, input().split())
print(27 + max(r, g + 1, b + 2))
