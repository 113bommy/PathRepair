c = 1

n, k =map(int, input().split())

if k >= 2 :
	tmp = 1
	for i in range(3,n+1):
		tmp *= i
	for i in range(2,n-1):
		tmp = tmp // i
	c += tmp

if k >= 3 :
	tmp = 1
	for i in range(4,n+1):
		tmp *= i
	for i in range(2,n-2):
		tmp = tmp // i
	c += tmp*2

if k == 4 :
	tmp = 1
	for i in range(5,n+1):
		tmp *= i
	for i in range(2,n-3):
		tmp = tmp // i
	c += tmp*9

print(c)