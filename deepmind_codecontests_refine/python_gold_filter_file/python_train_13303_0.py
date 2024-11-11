t = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

x = t[0] * (a[0] - b[0])
y = x + t[1] * (a[1] - b[1])
if x*y > 0:
	print(0)
elif x*y == 0:
	print('infinity')
elif abs(x) % abs(y) == 0:
	print(2 * (abs(x) // abs(y)))
else:
	print(2 * (abs(x) // abs(y)) + 1)