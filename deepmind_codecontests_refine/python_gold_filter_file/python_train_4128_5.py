n = int(input())

if n < 4:
	print(0)
	exit()

res = 0

for a in range(0, n + 1):
	for c in range(a, n + 1):
		b = a ^ c
		if a <= b and b <= c and a + b > c:
			res+=1

print(res)
