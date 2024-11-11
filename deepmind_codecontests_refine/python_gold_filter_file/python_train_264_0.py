EMPTY = '.'
X_STEP = 'x'


def is_winning(field):
    sign = X_STEP
    N = len(field)
    length = 3
    
    for row in range(N - length + 1):
        for col in range(N):
            has_vertical = True
            for drow in range(length):
                if field[row + drow][col] != sign:
                    has_vertical = False
                    break
            if has_vertical:
                return True

    for row in range(N):
        for col in range(N - length + 1):
            has_horizontal = True
            for dcol in range(length):
                if field[row][col + dcol] != sign:
                    has_horizontal = False
                    break
            if has_horizontal:
                return True

    for row in range(N - length + 1):
        for col in range(N - length + 1):
            has_straight_diagonal = True
            for shift in range(length):
                if field[row + shift][col + shift] != sign:
                    has_straight_diagonal = False
                    break
            if has_straight_diagonal:
                return True

    for row in range(length - 1, N):
        for col in range(N - length + 1):
            has_inverse_diagonal = True
            for shift in range(length):
                if field[row - shift][col + shift] != sign:
                    has_inverse_diagonal = False
                    break
            if has_inverse_diagonal:
                return True

    return False


def can_win(field):
    for row in range(len(field)):
        for col in range(len(field[row])):
            if field[row][col] == EMPTY:
                field[row][col] = X_STEP
                can_win = is_winning(field)
                field[row][col] = EMPTY
                if can_win:
                    return True

    return False


field = []
for _ in range(4):
    field.append([cell for cell in input()])

print("YES" if can_win(field) else "NO")
