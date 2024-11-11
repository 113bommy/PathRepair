import math
a, b, c = map(int, input().split(' '))
print(max(math.ceil(a*c/100 - b), 0))
