n , x = list(map(int,input().split(' ')))
m = x
c = 0
for i in range(n):
	s = input()
	if(s[0] == '+'):
		m += int(s[2:])
	else:
		d = int(s[2:])
		if(m >= d):
			m -= d
		else:
			c += 1
print(str(m) + " " + str(c))

