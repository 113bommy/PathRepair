a, b, c, d = list(map(int, input().split()))


def calc(p, t):
	return max((3*p)//10, p - (p//250) * t)


if calc(a, c) > calc(b, d):
	print("Misha")
elif calc(a, c) < calc(b, d):
	print("Vasya")
else:
	print("Tie")