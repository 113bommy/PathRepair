l = [int(input()) for i in range(5)]

import math

print(sum([math.ceil(i/10) * 10 for i in l]) - max([math.ceil(i/10) * 10 - i for i in l]))