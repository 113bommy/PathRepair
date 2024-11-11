from math import *


a, b, c = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
m = -1
if a == 0 or b == 0:
    print(abs(x2 - x1) + abs(y2 - y1))
else:
    tr = [[[x1, ((a * x1 + c) / -b)], [((b * y1 + c) / -a), y1]],
          [[x2, ((a * x2 + c) / -b)], [((b * y2 + c) / -a), y2]]]

    for i in range(2):
        for j in range(2):
            sqr = sqrt((tr[0][i][0] - tr[1][j][0])*(tr[0][i][0] - tr[1][j][0]) + (tr[0][i][1] - tr[1][j][1])*(tr[0][i][1] - tr[1][j][1]))
            if m == -1:
                m = abs(x1 - tr[0][i][0]) + abs(y1 - tr[0][i][1]) + abs(x2 - tr[1][j][0]) + abs(y2 - tr[1][j][1]) + sqr
            else:
                m = min(abs(x1 - tr[0][i][0]) + abs(y1 - tr[0][i][1]) + abs(x2 - tr[1][j][0]) + abs(y2 - tr[1][j][1]) + sqr, m)
    print(min(m, abs(x2 - x1) + abs(y2 - y1)))
