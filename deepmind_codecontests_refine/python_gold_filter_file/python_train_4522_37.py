s = input()
t = input()

moves = []

def move(x, y):
	if (x1 < x):
		if (y1 < y):
			moves.append('LU')
			x -= 1
			y -= 1
			return x, y, 2
		elif (y1 == y):
			x -= 1
			moves.append('L')
			return x, y, 1
		elif (y1 > y):
			x -= 1
			y += 1
			moves.append('LD')
			return x, y, 2
	elif (x1 == x):
		if (y1 < y):
			y -= 1
			moves.append('U')
			return x, y, 1
		elif (y1 == y):
			return x, y, 0
		elif (y1 > y):
			y += 1
			moves.append('D')
			return x, y, 1
	elif (x1 > x):
		if (y1 < y):
			x += 1
			y -= 1
			moves.append('RU')
			return x, y, 2
		elif (y1 == y):
			x += 1
			moves.append('R')
			return x, y, 1
		elif (y1 > y):
			x += 1
			y += 1
			moves.append('RD')
			return x, y, 2

row_names = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

x0 = int(row_names.index(s[0]))
y0 = 8 - int(s[1])

x1 = int(row_names.index(t[0]))
y1 = 8 - int(t[1])

price = abs(x1 - x0) + abs(y1 - y0)
n = 0
x = x0
y = y0
while (price > 0):
	x, y, p = move(x, y);
	price -= p
	n += 1

print (n)
list(map(print, moves))