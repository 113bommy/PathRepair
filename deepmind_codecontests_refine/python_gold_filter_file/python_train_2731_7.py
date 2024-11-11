import sys

t = int(sys.stdin.readline())

yxs = [(0, 0), (1, 4), (2, 8), (3, 1), (4, 3), (5, 7), (6, 2), (7, 5), (8, 6)]
for _ in range(t):
    arr = [list(map(int, list(sys.stdin.readline().strip())))
           for _ in range(9)]

    for y, x in yxs:
        if arr[y][x] >= 1 and arr[y][x] < 9:
            arr[y][x] += 1
        elif arr[y][x] == 9:
            arr[y][x] -= 1

    for j in arr:
        print("".join(list(map(str, j))))
