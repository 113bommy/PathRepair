
def f(k):
	return ((2 ** k) - 1) * (2 ** (k - 1))

k, n = 1, int(input())
i, maxi = f(k), -1
while i <= n:
	if n % i == 0:
		maxi = i
	i = f(k + 1)
	k += 1

print(maxi)
