from collections import defaultdict
import math
mod = 1000000007

pos = defaultdict(int)
neg = defaultdict(int)
zero = 0

n = int(input())
for _ in range(n):
	a, b = list(map(int, input().split()))
	if a == b == 0:
		zero += 1
	elif a == 0:
		pos[(0, 1)] += 1
	elif b == 0:
		neg[(0, 1)] += 1
	else:
		c = a * b
		g = math.gcd(a, b)
		a, b = abs(a // g), abs(b // g)
		if c > 0:
			pos[(a, b)] += 1
		elif c < 0:
			neg[(b, a)] += 1

cnt = 1
for x in pos.keys():
	if x in neg.keys():
		cnt = (cnt * (pow(2, pos[x], mod) + pow(2, neg[x], mod) - 1)) % mod
		del neg[x]
	else:
		cnt = (cnt * pow(2, pos[x], mod)) % mod

for x in neg.keys():
	cnt = (cnt * pow(2, neg[x], mod)) % mod

print((zero + cnt - 1) % mod)