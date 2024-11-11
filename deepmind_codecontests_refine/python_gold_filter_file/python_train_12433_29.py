__author__ = 'Eddie'
import sys


def get_filehandler(is_file):
    if is_file:
        return open(file="data")
    else:
        import sys

        return sys.stdin


# custom starts

def get_count(board):
    cnt_x, cnt_z, cnt_p = 0, 0, 0
    for item in board:
        for alpha in item:
            if alpha == "X":
                cnt_x += 1
                continue
            if alpha == ".":
                cnt_p += 1
                continue
            if alpha == "0":
                cnt_z += 1
                continue
    return cnt_x, cnt_z, cnt_p


def get_result(board):
    cnt = get_count(board)
    if cnt[0] - cnt[1] != 1 and cnt[0] - cnt[1] != 0:
        return "illegal"
    return get_winner(cnt, board)


def get_winner(cnt, board):
    mark = None
    for l in board:
        if l[0] == l[1] == l[2] != ".":
            if mark:
                return "illegal"
            mark = l[0]
    if not mark:
        for i in range(0, 3):
                if board[0][i] == board[1][i] == board[2][i] != ".":
                    if mark:
                        return "illegal"
                    mark = board[0][i]

    if board[0][0] == board[1][1] == board[2][2] != ".":
        mark = board[0][0]
    elif board[0][2] == board[1][1] == board[2][0] != ".":
        mark = board[0][2]
    if mark == "X":
        if cnt[0] <= cnt[1]:
            return "illegal"
        return "the first player won"
    elif mark == "0":
        if cnt[0] > cnt[1]:
            return "illegal"
        return "the second player won"
    if cnt[2] != 0:
        if cnt[0] == cnt[1]:
            return "first"
        else:
            return "second"
    else:
       return "draw"





if __name__ == '__main__':
    fh = get_filehandler(is_file=False)
    # fh = get_filehandler(is_file=True)

    board = [s.rstrip() for s in fh.readlines()]
    result = get_result(board)

    print(result)





