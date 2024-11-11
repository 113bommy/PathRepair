c = [1868, 1912, 1926, 1989]

e, y = [int(num) for num in input().split()]
if e > 0:
    print(c[e - 1] + y - 1)
else:
    if y < c[1]:
        print('M{}'.format(y - c[0] + 1))
    elif y < c[2]:
        print('T{}'.format(y - c[1] + 1))
    elif y < c[3]:
        print('S{}'.format(y - c[2] + 1))
    else:
        print('H{}'.format(y - c[3] + 1))