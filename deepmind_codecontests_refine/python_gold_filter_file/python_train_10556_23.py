if __name__ == '__main__':
    x, y = map(int, input().split())
    if x < 0:
        if y > 0:
            print(' '.join(map(str, [x - y, 0, 0, y - x])))
        if y < 0:
            print(' '.join(map(str, [x + y, 0, 0, y + x])))
    if x > 0:
        if y > 0:
            print(' '.join(map(str, [0, y + x, x + y, 0])))
        if y < 0:
            print(' '.join(map(str, [0, y - x, x - y, 0])))
