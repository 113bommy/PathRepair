def main():
	s = list(input().strip())
	i = -1
	n = len(s)
	b = [0] * n
	for j in range(n):
		if s[j] == 'a':
			if i != -1:
				b[i] ^= 1
				b[j-1] ^= 1
			i = j
	if i != -1:
		b[i] = 1

	for x in b:
		print(x, end=' ')
	print()


if __name__ == '__main__':
	main()