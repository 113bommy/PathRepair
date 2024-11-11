"""
    (0, 0) (0, 1) (0, 2)
    (1, 0) (1, 1) (1, 2)
    (2, 0) (2, 1) (2, 2)
"""
d = dict()
ans = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for i in range(3):
    d[i] = list(map(int, input().split()))
for i in range(3):
    for j in range(3):
        if i == 0 and j == 0:
            s = d[0][1]+d[1][0]

        elif i == 0 and j == 1:
            s = d[0][0]+d[0][2]+d[1][1]

        elif i == 0 and j == 2:
            s = d[0][1]+d[1][2]

        elif i == 1 and j == 0:
            s = d[0][0]+d[1][1]+d[2][0]

        elif i == 1 and j == 1:
            s = d[0][1]+d[1][0]+d[2][1]+d[1][2]

        elif i == 1 and j == 2:
            s = d[0][2]+d[1][1]+d[2][2]

        elif i == 2 and j == 0:
            s = d[1][0]+d[2][1]

        elif i == 2 and j == 1:
            s = d[2][0]+d[1][1]+d[2][2]

        elif i == 2 and j == 2:
            s = d[2][1]+d[1][2]

        else:
            continue

        if s % 2 == 1:
            ans[i][j] = d[i][j] % 2
        else:
            ans[i][j] = 1-d[i][j] % 2
for i in range(3):
    for j in range(3):
        print(ans[i][j], end="")
    print()