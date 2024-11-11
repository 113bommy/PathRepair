for _ in range(int(input())):
    n = int(input())
    s = [input(), input()]
    cur = 0
    x, y = 0, 0
    b = False
    while 1:
        if x == 1 and y == n:
            b = True
            break
        elif y >= n:
            break
        elif cur == 1 and s[x][y] < '3':
            break
        elif cur == 0 and s[x][y] < '3':
            y += 1
        elif cur == 0 and s[x][y] > '2':
            x = 1 - x
            cur = 1 - cur
        elif cur == 1 and s[x][y] > '2':
            y += 1
            cur = 1 - cur
    print("YNEOS"[not b::2])
