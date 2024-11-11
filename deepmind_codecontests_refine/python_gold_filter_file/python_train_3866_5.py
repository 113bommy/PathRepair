def main():
	n = int(input())
	s = ' ' + input()
	a = [0] * (n + 1)
	for i in range(1, n + 1):
		if s[i] == '(':
			a[i] = a[i - 1] + 1
		else:
			a[i] = a[i - 1] - 1
	# print(a) # debug
	if a[n] != 2 and a[n] != -2:
		print(0)
		return
	if min(a) < -2:
		print(0)
		return
	if a[n] == 2:
		if min(a) < 0:
			print(0)
			return
		for i in range(n, -1, -1):
			if a[i] == 1:
				print(s[(i + 1):].count('('))
				break
	else:
		for i in range(n):
			if a[i] == -1:
				print(s[:i + 1].count(')'))
				break



if __name__ == '__main__':
	main()