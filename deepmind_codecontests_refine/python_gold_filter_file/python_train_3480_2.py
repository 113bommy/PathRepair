a,b,c,d = map(int,input().split())
if d > b: d = b
k = (b // d)
if b % d > 0: k += 1
i = 0
while k > 0:
	if a > c + 1:a = c + 1
	if k >= a:
		i += 1
		k -= a
		c -= a - 1
	elif k == 1:
		i += 1
		k -= 1
	else:
		i += 1
		k = 0
	if c == 0:
		i += k
		break
print(i)