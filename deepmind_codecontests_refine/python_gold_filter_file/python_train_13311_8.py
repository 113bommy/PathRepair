import math
a = 100000
for n in range(int(input())):
	a = math.ceil(a*105/100000)*1000
print(int(a))