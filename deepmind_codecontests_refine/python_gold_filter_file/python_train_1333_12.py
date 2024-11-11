m = 10
x = 0

for i in range(5):
	n = int(input())
	if n%10 == 0:
		x += n
		continue
	elif n%10 < m:
		m = n%10
	x += n - n%10 +10
	
print(x -10 + m)
