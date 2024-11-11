from fractions import gcd
a, b, n = map(int, input().split())
si, asi = 0, 0
ans = 0
while n > 0:
	si = gcd(n, a)
	n = n - si
	if n > 0:
		ans = 1
	asi = gcd(n, b)
	n = n - asi
	if n > 0:
		ans = 0
print(ans)


