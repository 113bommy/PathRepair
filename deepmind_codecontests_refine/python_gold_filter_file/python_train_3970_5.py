prob_len = int(input())
strings = list()


for _ in range(prob_len * 2 - 2):
    strings.append(input().strip())

sorted_strings = sorted(enumerate(strings), key=lambda x: len(x[1]))
answers = [None] * len(sorted_strings)

last_p = ''
last_p_idx = None
last_s = ''
last_s_idx = None
for x in range(prob_len - 1):
    a_idx, a = sorted_strings[x * 2] 
    b_idx, b = sorted_strings[x * 2 + 1]

    is_a_prefix = None

    if len(a) == 1:
        is_a_prefix = True
    # elif a == b:
    #     is_a_prefix = True
    elif a.startswith(last_p) and b.endswith(last_s):
        is_a_prefix = True
    elif a.endswith(last_s) and b.startswith(last_p):
        is_a_prefix = False
    else:
        for idx in range(len(answers)):
            if answers[idx] == 'S':
                answers[idx] = 'P'
            elif answers[idx] == 'P':
                answers[idx] = 'S'

        last_s = strings[last_p_idx]
        last_p = strings[last_s_idx]
        if a.startswith(last_p) and b.endswith(last_s):
            is_a_prefix = True
        elif a.endswith(last_s) and b.startswith(last_p):
            is_a_prefix = False
        else:
            raise Exception()

    # print(last_p, last_s, a, b, is_a_prefix)

    if is_a_prefix:
        answers[a_idx] = 'P'
        last_p = a
        last_p_idx = a_idx
        answers[b_idx] = 'S'
        last_s = b
        last_s_idx = b_idx
    else:
        answers[a_idx] = 'S'
        last_s = a
        last_s_idx = a_idx
        answers[b_idx] = 'P'
        last_p = b
        last_p_idx = b_idx



print(''.join(answers))

