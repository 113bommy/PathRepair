s = [input() for i in range(2)]
n = len(s[0])


def divconq(a, b):
    if a + 1 >= b:
        return 0
    for i in range(a, b):
        sq1 = [s[0][i], s[1][i]]
        if sq1 == ['X', 'X']:
            # 1
            # 1
            return divconq(a, i) + divconq(i + 1, b)

    for i in range(a, b - 1):
        sq2 = [s[0][i], s[0][i + 1], s[1][i], s[1][i + 1]]
        if sq2 == ['X', 'X', '0', '0'] or sq2 == ['0', '0', 'X', 'X']:
            # 11 00
            # 00 11
            return divconq(a, i + 1) + divconq(i + 1, b)
        if sq2 == ['X', '0', '0', 'X'] or sq2 == ['0', 'X', 'X', '0']:
            # 10 01
            # 01 10
            return divconq(a, i + 1) + divconq(i + 1, b)

    for i in range(a, b):
        sq1 = [s[0][i], s[1][i]]
        if sq1 == ['X', '0'] or sq1 == ['0', 'X']:
            # 1 0
            # 0 1
            if i == a:
                return 1 + divconq(i + 2, b)
            if i == b - 1:
                return divconq(a, i - 1) + 1
            return max(
                    divconq(a, i - 1) + 1 + divconq(i + 1, b),
                    divconq(a, i) + 1 + divconq(i + 2, b))

    # all 0
    return (b - a) // 3 * 2 + ((b - a) % 3 == 2)


print(divconq(0, n))
