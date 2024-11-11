
import math
n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
t1 = t2 = t3 = ti = 0.0
for a, b in zip(x, y):
	d1 = abs(a - b)
	ti = max(ti, d1)
	t1 += d1
	t2 += d1**2
	t3 += d1**3
print(t1)
print(math.sqrt(t2))
print(t3 ** (1.0/3))
print(ti)