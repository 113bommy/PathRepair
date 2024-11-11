n = int(input())

import math
x = math.ceil(n/1.08)
if n == math.floor(x*1.08):
	print(x)
else:
	print(':(')