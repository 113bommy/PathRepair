


def sol_badges(b,g,n):
	counter = 0
	for boys in range(0,min(n+1,b+1)):
		for girls in range(0,min(g+1,n+1)):
			# print(boys,girls)
			if boys+girls == n :
				# print(boys,girls)
				counter += 1
	return counter











if __name__ == '__main__':
	b = int(input())
	g = int(input())
	n = int(input())
	out = sol_badges(b,g,n)
	print(out)