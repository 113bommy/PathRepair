x = input().split()
x.sort()
for i in range(len(x)):
	x[i] = int(x[i])
x.sort()
p = 2
n = 100
for j in range(2):
	if x[j] + x[j + 1] > x[j + 2]: 
		n = 300
	elif x[j] + x[j + 1] == x[j + 2]: 
		n = max(n, 200)
	else: 
		n = max(n, 100)
if n == 300:
	print('TRIANGLE')
elif n == 200:
	print('SEGMENT')
else:
	print('IMPOSSIBLE')