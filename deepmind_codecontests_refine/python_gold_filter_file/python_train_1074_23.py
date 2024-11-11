from math import pi


def main():
    input()
    l = sorted(map(int, input().split()))
    sign = (1, 0)[len(l) & 1]
    print((sum(_ * _ for _ in l[sign::2]) - sum(_ * _ for _ in l[1 - sign::2])) * pi)


if __name__ == '__main__':
    main()