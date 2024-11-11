from sys import stdin
n, m = map(int, stdin.readline().split())
board = []
for _ in range(n):
    row = list(map(int, stdin.readline().split()))
    board.append(row)

for i in range(n):
    for j in range(m):
        if (i+j)%2 == 0:
            board[i][j] = 720720
        else:
            board[i][j] = 720720 + board[i][j]**4

for row in board:
    print(' '.join(map(str, row)))
