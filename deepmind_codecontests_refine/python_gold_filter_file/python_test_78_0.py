
import math

def case():
	n = int(input())
	a = list(map(int, input().split()))

	if all(x == 0 for x in a):
		print(' '.join(map(str, range(1, n+1))))
		return

	counts = [0] * 30
	# counts[i] -> # of elements in a that have 2^i bit set

	for x in a:
		for i in range(30):
			if (1 << i) & x:
				counts[i] += 1

	factors = []
	for cnt in counts:
		if cnt == 0:
			continue

		upper = math.ceil(math.sqrt(cnt))
		f = set()
		for i in range(1, upper+1):
			if cnt % i == 0:
				f.add(i)
				f.add(cnt // i)
		factors.append(f)

	while len(factors) > 1:
		a = factors.pop()
		factors[-1] &= a
	print(' '.join(map(str, sorted(factors[0]))))




def main():
	T = int(input())
	for _ in range(T):
		case()


if __name__ == '__main__':
	main()