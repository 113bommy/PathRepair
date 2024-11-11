def isComposite(n):
	d = 2
	while d * d <= n:
		if n % d == 0:
			return True
		d += 1
	return False

def main():
	num = int(input())
	a = int(num / 2)
	b = num - a
	while not isComposite(a) or not isComposite(b):
		a -= 1
		b += 1
	print(str(a) + " " + str(b))

main()