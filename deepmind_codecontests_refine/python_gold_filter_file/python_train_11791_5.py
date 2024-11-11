def solve():
	K = int(input())
	minimum = 1
	for i in range(1, 42):
		if i ** 10 <= K:
			minimum = i
		else:
			break
	ans = [minimum] * 10

	prod = minimum ** 10
	i = 9
	while i >= 0:
		if prod >= K:
			break
		prod = prod // ans[i]
		ans[i] += 1
		prod *= ans[i]
		i -= 1
	cf = 'codeforces'
	ansString = ""
	for i in range(10):
		ansString += cf[i] * ans[i]
	return ansString
		


def main():
	print(solve())


if __name__ == '__main__':
	main()