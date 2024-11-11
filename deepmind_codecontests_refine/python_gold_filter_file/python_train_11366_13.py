def findGCD(a, b):
	while b != 0:
		r = a % b
		a = b
		b = r
	return a

values = input().split()

simNum = int(values[0])
antisNum = int(values[1])
stonesNum = int(values[2])

stonesTaken = 0
antisWins = ''
simonWins = ''
turn = True # flag for player's turn 

while(True):
	if turn:
		stonesTaken = findGCD(simNum, stonesNum)
		stonesNum -= stonesTaken
		if stonesNum < 0:
			antisWins = 1
			break
		turn = False # opponent plays next.
	else:
		stonesTaken = findGCD(antisNum, stonesNum)
		stonesNum -= stonesTaken
		if stonesNum < 0:
			simonWins = 0
			break
		turn = True # opponent plays next.

if antisWins:
	print(antisWins)
else:
	print(simonWins)
