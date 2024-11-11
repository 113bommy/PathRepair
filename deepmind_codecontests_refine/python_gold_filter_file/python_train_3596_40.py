ni,xi = input().split()
n = int(ni)
x = int(xi)
ls = []
kid = 0
for i in range(n):
	ls.append(input().split())


for i in range(n):
	if ls[i][0]=='+':
		x += int(ls[i][1])
	elif ls[i][0]=='-' and int(ls[i][1])<=x:
		x -= int(ls[i][1])
	else:
		kid += 1


print(x,kid)
