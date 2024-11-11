dict = {'Q':9, 'R':5, 'B':3, 'N':3, 'P':1, 'K':0}
white, black = 0, 0
for x in range(0, 8):
	boardLine = input()
	for c in boardLine:
		if c.isupper():
			white += dict.get(c)
		elif dict.get(c.upper()) != None:
			black += dict.get(c.upper())
#print(white, black)
if (white > black):
	print("White")
elif white == black:
	print("Draw")
else:
	print("Black")

