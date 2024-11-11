
def main():
	q = int(input())

	for _ in range(q):
		n = input()
		
		ln = len(n)
		nb = int(n)
		tab = []
		for x in range(1,10):
			tab.append(int(f"{str(x)}"*ln))
		f = True
		for x in range(9):
			if tab[x] > nb:
				print(9*ln - (9-x))
				f = False
				break
		if f:
			print(9*ln)




main()
