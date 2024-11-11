# your code goes here
t = int(input())
for j in range(t):
	t = input().split(" ")
	f = int(t[0])
	i = int(t[1])
	e = int(t[2])
	if f + e <= i:
		print(0, end='\n')
	else:
		if f <= i:
			e -= i - f + 1
			f = i + 1
		a = max(0, (i + e - f) // 2 + 1)
		print(e - a + 1, end='\n')
