def str_inp(n):
    return [input() for x in range(n)]


from collections import *

s, dic = str_inp(8), defaultdict(int, {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1, '.': 0})
white, black = 0, 0

for i in range(8):
    for j in range(8):
        if s[i][j].isupper():
            white += dic[s[i][j].lower()]
        else:
            black += dic[s[i][j]]

if white > black:
    print('White')
elif white < black:
    print('Black')
else:
    print('Draw')
