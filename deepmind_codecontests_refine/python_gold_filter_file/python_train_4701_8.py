import sys
n = int(input())
s = input()
if n % 2 == 1 or s[0] == ')' or s[-1] == '(':
	print (':(')
	sys.exit(0)
n -= 2
s = s[1:-1]
mas = []
kol1 = 0
kol2 = 0
for i in range(n):
	if s[i] == '?':
		mas.append(0)
	elif s[i] == '(':
		mas.append(-1)
		kol1 += 1
	else:
		mas.append(1)
		kol2 += 1
if max(kol1, kol2) * 2 > n:
	print (":(")
	sys.exit(0)
#print (mas)
#print (kol1, kol2)
x = 0
y = 0
if kol1 > kol2:
	x = n // 2 - kol1
	y = kol1 - kol2 + n // 2 - kol1
else:
	x = kol2 - kol1 + n // 2 - kol2
	y = n // 2 - kol2
#print (x, y)
for i in range(n):
	if mas[i] != 0:
		continue
	if x > 0:
		mas[i] = -1
		x -= 1
	else:
		mas[i] = 1
#print (mas)
kol = 0
for i in range(n):
	kol += mas[i]
	if kol > 0:
		print (":(")
		sys.exit(0)
print ('(', end = '')
for i in range(n):
	if mas[i] == -1:
		print ('(', end = '')
	else:
		print (')', end = '')
print (')')



