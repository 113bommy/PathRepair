w = {'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 1, 'K': 0}
b = {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1, 'k': 0}

white = 0
black = 0

for i in range(8):
    s = input()
    for j in s:
        if j in w:
            white += w[j]
        elif j in b:
            black += b[j]

if white < black:
    print('Black')
elif white > black:
    print('White')
else:
    print('Draw')