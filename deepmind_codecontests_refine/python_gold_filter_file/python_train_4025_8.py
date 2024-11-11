from math import ceil


def main():
    tmp = list(map(int, input().split()))
    t = tmp[0] * 60 + tmp[1]

    h, d, c, n = list(map(int, input().split()))

    a = c * ceil(h / n)

    if t >= 20 * 60:
        b = (0.8 * c * ceil(h / n))
    else:
        b = (0.8 * c * ceil((d * (20 * 60 - t) + h) / n))

    print('{:f}'.format(a if a < b else b))


if __name__ == '__main__':

    main()
