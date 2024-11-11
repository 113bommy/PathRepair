#168A
import math
n, x, y = map(int, input().split())
print(max(0,math.ceil((n*y)/100) - x))
