import math
n = int(input())
a = [int(x) for x in input().split()]
print(max(1+math.floor(sum(a)/n*2), max(a)))
