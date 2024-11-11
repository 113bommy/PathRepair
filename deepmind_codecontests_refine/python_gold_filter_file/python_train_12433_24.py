def check_row_column(field, c, i):
    win_row = True
    win_column = True
    for j in range(3):
        if field[i][j] != c:
            win_row = False
        if field[j][i] != c:
            win_column = False

    # if win_row and win_column:
    #     return None
    return win_row or win_column


def check_rows_columns(field, c):
    # win = []
    for i in range(3):
        if check_row_column(field, c, i):
            return True
    return False
    #     row_column = check_row_column(field, c, i)
    #     if row_column is None:
    #         return None
    #     else:
    #         win.append(row_column)
    # if sum(win) > 1:
    #     return None
    # return any(win)


def check_diags(field, c):
    win_diag_1 = True
    win_diag_2 = True
    for i in range(3):
        if field[i][i] != c:
            win_diag_1 = False
        if field[i][2 - i] != c:
            win_diag_2 = False

    # if win_diag_1 and win_diag_2:
    #     return None
    return win_diag_1 or win_diag_2


def check_win(field, c):
    # rows_columns = check_rows_columns(field, c)
    # diags = check_diags(field, c)
    # if rows_columns is None or diags is None:
    #     return None
    return check_rows_columns(field, c) or check_diags(field, c)


def main():
    field = []
    cross = 0
    zero = 0
    draw = True

    for _ in range(3):
        row = input()
        arr = []
        for c in row:
            arr.append(c)
            if c == "X":
                cross += 1
            elif c == "0":
                zero += 1
            elif c == ".":
                draw = False
        field.append(arr)

    if draw and cross != zero + 1 or not draw and cross != zero + 1 and cross != zero:
        print("illegal")
        return

    win_cross = check_win(field, "X")
    win_zero = check_win(field, "0")

    # if (win_zero is None or win_cross is None or
    if (win_cross and win_zero or
                win_cross and cross != zero + 1 or
                win_zero and cross != zero):
        print("illegal")
        return

    if win_cross:
        print("the first player won")
    elif win_zero:
        print("the second player won")
    elif draw:
        print("draw")
    elif cross == zero:
        print("first")
    else:
        print("second")


if __name__ == '__main__':
    main()
