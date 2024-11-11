def check2x2(mpx, i, j):
    sumNW = mpx[i - 1][j] + mpx[i - 1][j - 1] + mpx[i][j - 1]
    if sumNW == 3:
        return True
    sumSW = mpx[i][j - 1] + mpx[i + 1][j - 1] + mpx[i + 1][j]
    if sumSW == 3:
        return True
    sumSE = mpx[i + 1][j] + mpx[i + 1][j + 1] + mpx[i][j + 1]
    if sumSE == 3:
        return True
    sumNE = mpx[i][j + 1] + mpx[i - 1][j + 1] + mpx[i - 1][j]
    if sumNE == 3:
        return True
    return False

n, m, k = map(int, input().split())

mpx = [[0 for i in range(m + 2)] for j in range(n + 2)]

step = 1
while step <= k:
    i, j = map(int, input().split())
    mpx[i][j] = 1
    if check2x2(mpx, i, j):
        print(step)
        break
    step += 1
else:
    print(0)