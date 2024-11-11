s = input()

def ch_c(x):
	c = 0
	l = []
	for i in range(1, len(x)*9+1):
		if (int(x)-i)>0 and (int(x)-i)+(o_s(int(x)-i)) == int(x):
			c += 1
			l.append(int(x)-i)
	l.append(c)
	return(l)

def o_s(n):
	x = sum(list(map(int, str(n))))
	return x

o = ch_c(s)

print(o[-1])
for i in range(len(o)-2,-1,-1):
	print(o[i])