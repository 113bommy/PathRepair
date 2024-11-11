#http://codeforces.com/problemset/problem/519/A
white = {"Q":9,"R":5,"B":3,"P":1,"N":3, "K": 0}
black = {"q":9,"r":5,"b":3,"p":1, "n":3, "k": 0}
board = []
whiteval = 0
blackval = 0
#print(white["Q"])
for x in range(8):
	word = list(input())
	board.append(word)


for x in board:
	
	for i in x:
		
		if i in white:
			whiteval += white[i]
		elif i in black:
			blackval += black[i]
		else:
			continue


if whiteval > blackval:
	print("White")
elif blackval> whiteval:
	print("Black")
else:
	print("Draw")