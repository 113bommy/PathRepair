def f1():
    t = 0
    for y, line in enumerate(M):
        for x, cell in enumerate(line):
            if M[y][x] == '1':
                f2(x, y)
                t += 1
    return t


def f2(x, y):
    if x < 0 or len(M[0]) == x or y < 0 or len(M) == y:
        return
    if M[y][x] == '1':
        M[y][x] = '0'
        f2(x, y-1)
        f2(x, y+1)
        f2(x+1, y)
        f2(x-1, y)


M = []
while True:
    try:
        line = input()
        if line == '':
            print(f1())
            M = []
        else:
            M.append(list(line))
    except EOFError:
        print(f1())
        break