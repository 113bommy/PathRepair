"""
The king is left alone on the chessboard. In spite of this loneliness, he doesn't lose heart, because he has business of national importance. For example, he has to pay an official visit to square t. As the king is not in habit of wasting his time, he wants to get from his current position s to square t in the least number of moves. Help him to do this.

In one move the king can get to the square that has a common side or a common vertex with the square the king is currently in (generally there are 8 different squares he can move to).

# Input
The first line contains the chessboard coordinates of square s, the second line — of square t.

Chessboard coordinates consist of two characters, the first one is a lowercase Latin letter (from a to h), the second one is a digit from 1 to 8.

# Output
In the first line print n — minimum number of the king's moves. Then in n lines print the moves themselves. Each move is described with one of the 8: L, R, U, D, LU, LD, RU or RD.

L, R, U, D stand respectively for moves left, right, up and down (according to the picture), and 2-letter combinations stand for diagonal moves. If the answer is not unique, print any of them.
"""
def valid_coordinates():
    if (col_source < 'a' or col_source > 'h') or (col_destination < 'a' or col_destination > 'h') or (row_source < 1 or row_source > 8) or (row_destination < 1 or row_destination > 8):
        return 0
    else:
        return 1

def is_done():
    if source == destination:
        return 1
    else:
        return 0

def is_same_col():
    if col_source == col_destination:
        moves = row_destination - row_source
        no_moves = abs(moves)

        list.append([('D' if moves < 0 else 'U'), no_moves])
        count.append(no_moves)
        return 1
    else:
        return 0


def is_same_row():
    if row_source == row_destination:
        moves = ord(col_destination) - ord(col_source)
        no_moves = abs(moves)

        list.append([('R' if moves > 0 else 'L'), no_moves])
        count.append(no_moves)
        return 1
    else:
        return 0

def is_same_diagonal():
    no_moves = row_source - row_destination
    no_cols = ord(col_destination) - ord(col_source)

    if no_moves == no_cols:
        list.append([('R' if no_cols > 0 else 'L') + ('D' if no_moves > 0 else 'U'), abs(no_moves)])
        count.append(abs(no_moves))
        return 1
    else:
        return 0

def regular_move():
    global source
    global col_source
    global row_source

    # is right or left
    if col_destination > col_source:
        R_or_L = 'R'
        new_col_val = chr(ord(source[0]) + 1)
    else:
        R_or_L = 'L'
        new_col_val = chr(ord(source[0]) - 1)

    # is up or down
    if row_destination > row_source:
        D_or_U = 'U'
        new_row_val = row_source + 1
    else:
        D_or_U = 'D'
        new_row_val = row_source - 1

    source = new_col_val + str(new_row_val)

    col_source = source[0]
    row_source = int(source[1:])

    list.append([(R_or_L + D_or_U), 1])
    count.append(1)

source = input()
destination = input()

col_destination = destination[0]
row_destination = int(destination[1:])

col_source = source[0]
row_source = int(source[1:])

if valid_coordinates():
    list = []
    count = []

    while not is_done():
        if is_same_col():
            source = destination

        elif is_same_row():
            source = destination

        elif is_same_diagonal():
            source = destination

        else:
            regular_move()

print(sum(count))
for value in list:
    print((value[0] + '\n') * value[1], end='')
