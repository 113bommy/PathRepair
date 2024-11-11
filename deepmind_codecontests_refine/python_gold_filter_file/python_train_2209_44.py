


def main():
	q = int(input())

	for _ in range(q):
		n = int(input())
		s = 0
		while n > 0:
			ni = 1
			while ni*10 <= n:
				ni *= 10
			n -= ni
			s += ni
			n += ni//10
		print(s)


					




main()
    
        