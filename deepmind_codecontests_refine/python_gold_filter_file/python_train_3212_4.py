import sys
from itertools import accumulate

def solve():
    n, m, q = map(int, input().split())
    s = [[int(j) for j in input()] for i in range(n)]

    # 青マスの2次元累積和
    sxy = [list(accumulate(s[i])) for i in range(n)]

    for j in range(m):
        for i in range(n - 1):
            sxy[i + 1][j] += sxy[i][j]

    # 枝の2次元累積和(2n * 2mで管理)
    exy = [[0]*(2*m) for i in range(2*n)]

    for i in range(2*n - 1):
        if i % 2 == 0:
            for j in range(2*m - 1):
                exy[i][j + 1] += exy[i][j]
                if j % 2 == 0 and j < 2*m - 2:
                    exy[i][j + 1] += (s[i//2][j//2] == s[i//2][j//2 + 1] == 1)
        else:
            for j in range(2*m - 1):
                if j % 2 == 0:
                    exy[i][j] += (s[i//2][j//2] == s[i//2 + 1][j//2] == 1)

                exy[i][j + 1] += exy[i][j]

    for j in range(2*m):
        for i in range(2*n - 1):
            exy[i + 1][j] += exy[i][j]

    '''
    for i in range(2*n):
        print(exy[i], file=sys.stderr)
    '''

    for qi in range(q):
        x1, y1, x2, y2 = map(lambda x: x - 1, map(int, sys.stdin.readline().split()))

        nv = sxy[x2][y2]

        if x1 - 1 >= 0:
            nv -= sxy[x1 - 1][y2]
        if y1 - 1 >= 0:
            nv -= sxy[x2][y1 - 1]
        if x1 - 1 >= 0 and y1 - 1 >= 0:
            nv += sxy[x1 - 1][y1 - 1]

        ne = exy[2*x2][2*y2]

        if 2*x1 - 1 >= 0:
            ne -= exy[2*x1 - 1][2*y2]
        if 2*y1 - 1 >= 0:
            ne -= exy[2*x2][2*y1 - 1]
        if 2*x1 - 1 >= 0 and 2*y1 - 1 >= 0:
            ne += exy[2*x1 - 1][2*y1 - 1]

        ans = nv - ne

        print(ans)

if __name__ == '__main__':
    solve()