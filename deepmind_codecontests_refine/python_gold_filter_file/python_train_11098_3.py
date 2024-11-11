s,e = input().split()
n = int(input())
f = ['^','>','v','<']
a,b = 0,0
for i in range(4):
	if f[i] == s:
		a = i + 1
	if f[i] == e:
		b = i + 1
if n % 4 == 2 or n % 4 == 0:
	print('undefined')
else:
	if n % 4 == abs(a-b):
		if a > b:
			print('ccw')
		else:
			print('cw')
	else:
		if a > b:
			print('cw')
		else:
			print('ccw')
