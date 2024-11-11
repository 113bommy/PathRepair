

entrada = list(map(int,input().split(' ')))
l = entrada[0]
x = entrada[1]
y = entrada[2]


ok = True

res = 1

ax = True

if y >= l:
	y -= l
	res = 2
	

while(y >= l):
	if ax:
		res += 1
	else:
		res += 2
	ax = not ax 
		 
	y -= l

if y == 0:
	ok = False
if not ax:
	if x <= -l or x >= l or x == 0:
		ok = 0
	if x > 0:
		res += 1
else:
	if x >= (l/2) or x <= -(l/2):
		ok = 0


if ok:
	print(res)
else:
	print(-1)









