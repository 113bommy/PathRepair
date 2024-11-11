l = []
for i in range(1, 100):
	x = (2**i - 1)*(2**(i-1))
	if x > 100000:
		break
	l.append(x)

l = l[::-1]
k = int(input())
ans = 0
for i in l:
	if k % i == 0:
		print(i)
		break