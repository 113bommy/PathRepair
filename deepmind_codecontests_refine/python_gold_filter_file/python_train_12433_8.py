board = [input(),input(),input()]
os = board[0].count('0') + board[1].count('0') + board[2].count('0')
xs = board[0].count('X') + board[1].count('X') + board[2].count('X')
firstWon = 0
secondWon = 0
for i in range(3):
	if board[i] == "XXX": 
		firstWon = firstWon+1
	elif board[i] == "000": 
		secondWon = secondWon+1
	elif board[0][i] == '0' and board[1][i] == '0' and board[2][i] == '0': 
		secondWon = secondWon+1
	elif board[0][i] == 'X' and board[1][i] == 'X' and board[2][i] == 'X': 
		firstWon = firstWon+1
if board[0][0] == '0' and board[1][1] == '0' and board[2][2] == '0':
	secondWon = secondWon+10
elif board[0][2] == '0' and board[1][1] == '0' and board[2][0] == '0':
	secondWon = secondWon+1
elif board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X':
	firstWon = firstWon+1
elif board[0][2] == 'X' and board[1][1] == 'X' and board[2][0] == 'X':
	firstWon = firstWon+1
if xs - os > 1 or os > xs or (firstWon > 0 and secondWon>0) or (firstWon >0 and os == xs) or (secondWon >0 and xs!=os): print("illegal")
else:
	if firstWon >= 1: print("the first player won")
	elif secondWon >= 1: print("the second player won")
	elif not ('.' in board[0] or '.' in board[1] or '.' in board[2]): print('draw')
	elif xs == os: print("first")
	else: print("second")