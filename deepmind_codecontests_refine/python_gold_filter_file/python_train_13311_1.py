import math

n = eval(input())
yen = 100000
for i in range(n):
	yen += yen * 0.05
	yen = int(math.ceil(yen / 1000.0) * 1000)
print(yen)