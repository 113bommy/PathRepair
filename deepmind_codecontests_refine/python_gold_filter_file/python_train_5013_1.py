for _ in range(int(input())):
    no_ans = False
    ans = []

    s = input()
    c = list(sorted(set(s)))

    if len(c) == 1:
        ans = [c[0]]
    elif len(c) == 2:
        if ord(c[1]) - ord(c[0]) == 1:
            no_ans = True
        else:
            ans = [c[0], c[1]]
    elif len(c) == 3:
        if ord(c[2]) - ord(c[0]) == 2:
            no_ans = True
        elif ord(c[1]) - ord(c[0]) > 1:
            ans = [c[2], c[0], c[1]]
        else:
            ans = [c[0], c[2], c[1]]
    else:
        ans = list(reversed(c[0:-1:2])) + [c[-1]] + c[1:-1:2]

    res = ''.join([ch * s.count(ch) for ch in ans])
    print("No answer" if no_ans else res)
