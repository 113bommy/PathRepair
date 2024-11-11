for _ in range(int(input())):
    s = input()
    d = {'U': 0, 'D': 0, 'L': 0, 'R': 0}
    for c in s:
        d[c] += 1

    y = min(d['U'], d['D'])
    x = min(d['L'], d['R'])

    d['U'], d['D'] = y, y
    d['L'], d['R'] = x, x

    if 0 not in [x, y]:
        print(2*x+2*y)
        t = "".join([c * d[c] for c in ['U', 'L', 'D', 'R']])
        print(t)
    elif x == 0 and y != 0:
        print(2)
        print('UD')
    elif y == 0 and x != 0:
        print(2)
        print('LR')
    else:
        print(0)
