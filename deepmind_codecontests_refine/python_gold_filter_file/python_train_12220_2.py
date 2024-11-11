def main():
    x, y = map(int, input().split())
    r, t = max(abs(x), abs(y)), 0
    if x == r == 1 - y:
        t = 4
    elif x == r > -y:
        t = 3
    elif y == r > x:
        t = 2
    elif -x == r > y:
        t = 1
    print({(0, 0): 0, (1, 0): 0, (1, 1): 1, (0, 1): 2, (-1, 1): 2, (-1, 0): 3, (-1, -1): 3,
           (0, -1): 4, (1, -1): 4}[x, y] if r < 2 else r * 4 - t)


if __name__ == '__main__':
    main()
