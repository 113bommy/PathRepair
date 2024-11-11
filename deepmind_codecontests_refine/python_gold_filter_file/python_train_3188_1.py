def main():
	(n, k) = (int(x) for x in input().split())
	solver(n, k)

def solver(n, k):
	fives = findPow(n, 5)
	twos = findPow(n, 2)
	ans = n * 5**max(0, k - fives) * 2**max(0, k - twos)
	print(ans)

def findPow(n, k):
	count = 0
	while n % k == 0:
		n //= k
		count += 1
	return count

#solver(375, 4)
main()
