q = int(input())
for i in range(q):
    s = list(input())
    l, r, u, d = 0, 0, 0, 0
    for i in s:
        if i == 'L':
            l += 1
        elif i == 'R':
            r += 1
        elif i == 'U':
            u += 1
        else:
            d += 1
    a, b = min(l, r), min(u, d)
    if a == 0 and b == 0:
        print('0')
    elif a == 0:
        print('2')
        print('UD')
    elif b == 0:
        print('2')
        print('LR')
    else:
        print(2*a + 2*b)
        print(a*'L' + b*'U' + a*'R' + b*'D')
