def optimize_costs(c1, c2, c3, c4, c5, c6):
    c1 = min(c1, c2 + c6)
    c2 = min(c2, c1 + c3)
    c3 = min(c3, c2 + c4)
    c4 = min(c4, c3 + c5)
    c5 = min(c5, c4 + c6)
    c6 = min(c6, c5 + c1)

    return c1, c2, c3, c4, c5, c6


def main(input_f):
    t = int(input_f())
    for _ in range(t):
        x, y = map(int, input_f().split(' '))
        c1, c2, c3, c4, c5, c6 = map(int, input_f().split(' '))
        # c1 = +1 +1
        # c2 = 0 +1
        # c3 = -1 0
        # c4 = -1 -1
        # c5 = 0 -1
        # c6 = +1 0

        for _ in range(10):
            c1, c2, c3, c4, c5, c6 = optimize_costs(c1, c2, c3, c4, c5, c6)

        if x < 0 and y < 0:
            if x < y:
                print(-y * c4 + (y - x) * c3)
            else:
                print(-x * c4 + (x - y) * c5)
        elif x < 0 and y >= 0:
            print(-x * c3 + y * c2)
        elif x >= 0 and y < 0:
            print(x * c6 - y * c5)
        else:
            if x < y:
                print(x * c1 + (y - x) * c2)
            else:
                print(y * c1 + (x - y) * c6)


if __name__ == '__main__':
    #with open('input.txt') as f:
    #    main(f.readline)
    main(input)
