'''
Jana Goodman
2010 Beta Round #1

tic-tac-toe status give grid

'''

import sys

SIZE = 3


WINS = [{(r, c) for c in range(0, SIZE)}
        for r in range(0, SIZE)]
WINS += [{(c, r) for c in range(0, SIZE)}
         for r in range(0, SIZE)]
WINS += [{(r, r) for r in range(0, SIZE)}]
WINS += [{(r, SIZE - 1 - r) for r in range(SIZE - 1, -1, -1)}]

X = 'X'
OH = '0'
DOT = '.'

X_TURN = 'first'
O_TURN = 'second'
ILLEGAL = 'illegal'
X_WINS = 'the first player won'
O_WINS = 'the second player won'
DRAW = 'draw'

def get_data(file_name):
    result = list()
    try:
        for line in open(file_name, 'r').readlines():
            result.append(line.strip)
        return result
    except FileNotFoundError:
        print(f'File {file_name} not found.')

def is_winner(x_or_o, arr):
    for win in WINS:
        if len([(r, c) for r, c in arr if (r, c) in win]) == SIZE:
            return True
    return False

def get_verdict(grid):
    Xs = [(r, c) for c in range(0, SIZE) for r in range(0, SIZE)
            if grid[r][c] == X]
    OHs = [(r, c) for c in range(0, SIZE) for r in range(0, SIZE)
            if grid[r][c] == OH]
    dots = [(r, c) for c in range(0, SIZE) for r in range(0, SIZE)
            if grid[r][c] == DOT]
    Xlen, Olen, dot_len = len(Xs), len(OHs), len(dots)
    if sum([Xlen, Olen, dot_len]) != 9:
        return ILLEGAL
    dif = Xlen - Olen
    if dif not in [0, 1]:
        return ILLEGAL
    if is_winner(OH, OHs):
        if is_winner(X, Xs) or dif != 0:
            return ILLEGAL
        return O_WINS
    if is_winner(X, Xs):
        if dif != 1:
            return ILLEGAL
        return X_WINS
    if Xlen + Olen == 9:
        return DRAW
    if dif == 0:
        return X_TURN
    return O_TURN


if __name__ == '__main__':
#    grid = ['X0X', '.0.', '.X.']
    grid = [sys.stdin.readline().strip() for _ in range(0, SIZE)]
    print(F'{get_verdict(grid)}')