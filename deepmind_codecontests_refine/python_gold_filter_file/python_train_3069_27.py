white = {'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 1}
black = {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1}
w_score = 0
b_score = 0
for _ in range(8):
    s = input()
    for i in s:
        if i in white: w_score += white[i]
        if i in black: b_score += black[i]

if w_score > b_score: print('White')
elif b_score > w_score: print('Black')
else: print('Draw')
