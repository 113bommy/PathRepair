def snow(s):
    left, right, up, down = s.count('L'), s.count('R'), s.count('U'), s.count('D')
    m1, m2 = min(left, right), min(up, down)
    if m2 == 0 and m1 > 0:
        return 2, 'LR'
    elif m2 > 0 and m1 == 0:
        return 2, 'UD'
    return 2 * (m1 + m2), 'L' * m1 + 'U' * m2 + 'R' * m1 + 'D' * m2


for _ in range(int(input())):
    t = input()
    print(*list(snow(t)), sep='\n')
