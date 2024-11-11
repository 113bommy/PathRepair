__author__ = 'Darren'


def solve():
    import sys
    stdin = sys.stdin if True else open('data')

    vertices = [[float(x) for x in line] for line in map(str.split, stdin)]
    p = [sum(v[0] for v in vertices) / 3, sum(v[1] for v in vertices) / 3]

    step = 1
    while step > 1e-6:
        error = calc_error(p, vertices)
        if error < 1e-8:
            print('%.5f %.5f' % (p[0], p[1]))
            break
        if error > calc_error((p[0] + step, p[1]), vertices):
            p[0] += step
            continue
        if error > calc_error((p[0] - step, p[1]), vertices):
            p[0] -= step
            continue
        if error > calc_error((p[0], p[1] + step), vertices):
            p[1] += step
            continue
        if error > calc_error((p[0], p[1] - step), vertices):
            p[1] -= step
            continue
        step *= 0.5


def calc_error(p, vertices):
    ratios = [((p[0] - v[0]) ** 2 + (p[1] - v[1]) ** 2) ** 0.5 / v[2]
              for v in vertices]
    average = sum(ratios) / 3
    return ((ratios[0] - average) ** 2 + (ratios[1] - average) ** 2 +
            (ratios[2] - average) ** 2)


if __name__ == '__main__':
    solve()