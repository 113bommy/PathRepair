a = 0
b = 0
score = { 'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 1 }
for i in range(8):
	for x in input():
		if x.upper() in score:
			if x == x.upper():
				a += score[x.upper()]
			else:
				b += score[x.upper()]
if a > b:
	print('White')
elif a < b:
	print('Black')
else:
	print('Draw')