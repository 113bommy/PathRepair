moves = [
    {'F': lambda i, j, x: (i, min(n, j + x)), 'B': lambda i, j, x: (i, max(1, j - x))},
    {'F': lambda i, j, x: (min(m, i + x), j), 'B': lambda i, j, x: (max(1, i - x), j)},
    {'F': lambda i, j, x: (i, max(1, j - x)), 'B': lambda i, j, x: (i, min(n, j + x))},
    {'F': lambda i, j, x: (max(1, i - x), j), 'B': lambda i, j, x: (min(m, i + x), j)}]
turns = {'R': lambda i: (i + 1) % 4, 'L': lambda i: (i - 1) % 4}

while True:
    m, n = map(int, input().split())
    if not m:
        break
    i, j = 1, 1
    cci = 0
    while True:
        cmd = input()
        ch = cmd[0]
        if ch in 'FB':
            i, j = moves[cci][ch](i, j, int(cmd.split()[1]))
        elif ch in 'RL':
            cci = turns[ch](cci)
        else:
            print(i, j)
            break