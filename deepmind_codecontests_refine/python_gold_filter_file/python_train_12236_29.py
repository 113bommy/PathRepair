n,a,b = map(int, input().split())
if b< 0:
	while b != 0:
		a -= 1
		b += 1
		if  a == 0:
			a = n
		
else:
	while b != 0:
		a += 1
		b -= 1
		if a > n:
			a = 1
print(a)
	