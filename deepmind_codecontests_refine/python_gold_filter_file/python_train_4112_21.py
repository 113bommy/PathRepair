
#biti = n%(pow(10, i+1)) // pow(10, i)
#lownum = n % (pow(10, i+1))

def solve():
	n = int(input())

	width = 0
	for width in range(100):
		if n // pow(10, width) == 0:
			break

	total = 0
	for i in range(width-1):
		delta = (i+1)*(pow(10, i+1)-pow(10, i))
		#print("i: %3d, delta: %d"%(i, delta))
		total += delta

	delta = width*(n - pow(10, width-1) + 1)
	#print("i: %3d, delta: %d"%(width-1, delta))
	total += delta

	print(total)

if __name__ == "__main__":
	solve()
