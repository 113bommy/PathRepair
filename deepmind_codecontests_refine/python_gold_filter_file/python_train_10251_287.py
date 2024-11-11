num = int(input())

import math

mult = 1 if num%2 == 0 else -1
print(math.ceil(num/2) * mult)
