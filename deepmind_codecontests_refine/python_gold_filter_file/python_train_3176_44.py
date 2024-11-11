import random, math

n = [int(x) for x in input().split()]
if 10 ** n[0] - 1 < n[1]:
	print(-1)
	exit(0)
x = random.randint(10 ** (n[0] - 1), 10 ** n[0] - 1)
if x % n[1] != 0:
	x1 = (x // n[1]) * n[1]
	x2 = math.ceil(x / n[1]) * n[1]
print(x if x % n[1] == 0 else (x1 if x1 >= 10 ** (n[0] - 1) and x1 <= 10 ** n[0] else x2))