x, n = map(int, input().split())
f = []
i = 2
while i * i <= x:
	if x % i == 0:
		f.append(i)
		while x % i == 0:
			x //= i
	i += 1
if x > 1:
	f.append(x)

mod = int(1e9 + 7)
def ksm(a, k):
	ret = 1
	while k > 0:
		if k & 1:
			ret = ret * a % mod;
		a = a * a % mod
		k >>= 1
	return ret

ans = 1
for p in f:
	pp = p
	while pp <= n:
		ans *= ksm(pp, n // pp - n // (p * pp))
		# print(n // (p * pp), ksm(pp, n // pp - n // (p * pp)))
		ans %= mod
		pp *= p
print(ans)
