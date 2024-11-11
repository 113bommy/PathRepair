import sys
def fact(n):
	ret = 1
	for x in range(1, n + 1):
		ret = ret * x
	return ret

def C(n, k):
	return fact(n) // (fact(k) * (fact(n - k)))

def get(n):
	if n == 0:
		return 1
	if n == 1:
		return 3
	return 3 * 4 ** (n - 1)

n = int(input())
ret = 0
ans = 0
for x in range(n - 2 + 1):
	right = n - 2 - x
	left = x
	ans += 4 * get(left) * get(right)
print(ans)