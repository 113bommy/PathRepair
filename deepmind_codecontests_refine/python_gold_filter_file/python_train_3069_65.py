white = {"Q": 9, "R": 5, "B": 3, "N": 3, "P":1}
black = {"q": 9, "r": 5, "b": 3, "n": 3, "p":1}
wscore = 0
bscore = 0
for i in range(8):
    line = input()
    for s in line:
        if s in white:
            wscore += white[s]
        elif s in black:
            bscore += black[s]

if wscore > bscore:
    print("White")
elif wscore == bscore:
    print("Draw")
else:
    print("Black")