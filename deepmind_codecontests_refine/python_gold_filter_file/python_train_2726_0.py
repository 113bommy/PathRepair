_ = input()
r = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))

arr = [[0] * len(c) for _ in range(len(r))]


def solve():
    for i, x in enumerate(r):
        for j in range(0, x):
            arr[i][j] = 1
        if x < len(c):
            arr[i][x] = -1

    for i, x in enumerate(c):
        for j in range(0, x):
            if arr[j][i] == -1:
                return 0
            arr[j][i] = 1
        if x < len(r):
            if arr[x][i] == 1:
                return 0
            arr[x][i] = -1

    s = 0

    for row in arr:
        for x in row:
            s += x == 0
    return (1 << s) % 1000000007


print(solve())
