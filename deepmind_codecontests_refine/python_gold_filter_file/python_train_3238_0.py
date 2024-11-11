try:
    n = int(input())
    a = list(map(int, input().split()))

    commands = []
    max_neg_index = None
    neg_count = 0
    last_zero = None
    last_positive = None

    def add_command_1(pos1, pos2):
        commands.append(f'1 {pos1} {pos2}')

    def add_command_2(position):
        commands.append(f'2 {position}')

    for i in range(n):
        value = a[i]
        if value is None:
            continue
        elif value < 0:
            neg_count += 1
            if max_neg_index is None or value > a[max_neg_index-1]:
                max_neg_index = i + 1
        elif value == 0:
            if last_zero:
                add_command_1(last_zero, i+1)
            last_zero = i + 1
        else:
            if last_positive is not None:
                add_command_1(last_positive, i+1)
                a[last_positive-1] = None
            last_positive = i + 1


    if not neg_count % 2:
        max_neg_index = None

    last_negative = None

    for i in range(n):
        value = a[i]
        if value is None or value >= 0:
            continue
        if max_neg_index is not None and i == max_neg_index-1:
            continue

        if last_negative is not None:
            add_command_1(last_negative, i+1)
            value = a[last_negative-1] * value
            a[last_negative-1] = None
        last_negative = i + 1

    if max_neg_index is not None and last_zero is not None:
        add_command_1(max_neg_index, last_zero)
    elif max_neg_index is not None:
        if len(commands) < n-1:
            add_command_2(max_neg_index)

    if last_negative is not None and last_positive is not None:
        add_command_1(last_negative, last_positive)
    if last_zero is not None:
        if len(commands) < n-1:
            add_command_2(last_zero)

    print('\n'.join(commands))
except Exception as exc:
    import traceback
    print(traceback.format_exc())
