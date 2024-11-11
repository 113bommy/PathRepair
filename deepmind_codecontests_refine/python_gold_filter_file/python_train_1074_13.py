import math
n = int(input())
r = [int(x) for x in input().split()]
spaces = [math.pi * rad ** 2 for rad in sorted(r)[::-1]]
print(sum(spaces[::2]) - sum(spaces[1::2]))
