
from collections import defaultdict
from math import log2, ceil

n = int(input())
if n == 1:
	print(1, 0)
	exit()

d = defaultdict(int)

while n%2 == 0:
	d[2] += 1
	n //= 2

ind = 3
while ind <= int(n**0.5)+1:
	while n%ind == 0:
		d[ind] += 1
		n //= ind
	ind += 2

if n != 1:
	d[n] += 1

# print(d)

ma = -1
ans = 1
arr = []
for x in d:
	ma = max(ma, d[x])
	arr += [d[x]]
	ans *= x

if arr.count(ma) == len(arr) and (2**30)%ma == 0:
	print(ans, ceil(log2(ma)))
else:
	print(ans, 1 + ceil(log2(ma)))


# if arr.count(1) == len(arr):
# 	print(ans, 0)
# elif arr.count(2)

