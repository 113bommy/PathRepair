chess = {'Q':9, 'R':5, 'B':3, 'N':3, 'P':1}
white = "QRBNP"
black = "qrbnp"
w = b = 0
for i in range(8):
    for j in input():
        if j in white:
            w += chess[j]
        elif j in black:
            b += chess[j.upper()]
if w > b:
    print("White")
elif w == b:
    print("Draw")
else:
    print("Black")