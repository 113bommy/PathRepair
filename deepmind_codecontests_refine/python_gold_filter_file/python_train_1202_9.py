moves = list(input())

up = 0
down = 0
right = 0
left = 0

if len(moves) is 2:
    if moves[0] is 'L' and moves[1] is 'R' or moves[1] is 'L' and moves[0] is 'R':
        print('0')
    elif moves[0] is 'U' and moves[1] is 'D' or moves[1] is 'U' and moves[0] is 'D':
        print('0')
    else:
        print('1')
elif len(moves) % 2 is not 0:
    print('-1')
else:
    for move in moves:
        if move is 'U':
            up += 1
        elif move is 'D':
            down += 1
        elif move is 'R':
            right += 1
        elif move is 'L':
            left += 1

    min_up_down = 0
    min_left_right = 0

    if up < down:
        min_up_down = down - up
    else:
        min_up_down = up - down

    if right < left:
        min_left_right = left - right
    else:
        min_left_right = right - left

    final_moves = 0

    # print(min_left_right, min_up_down)
    if min_left_right is 0:
        final_moves = int(min_up_down / 2)
        print(final_moves)
    elif min_up_down is 0:
        final_moves = int(min_left_right / 2)
        print(final_moves)
    elif min_left_right is min_up_down:
        print(min_up_down)
    else:
        print(int((min_left_right + min_up_down) / 2))

