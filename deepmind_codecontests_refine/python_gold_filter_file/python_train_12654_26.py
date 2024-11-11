def test_square(a):
    n = len(a)
    summ = sum(a[0])
    for i in range(1, n):
        if sum(a[i]) != sum(a[0]):
            return False
    summs = [0] * n
    for i in range(n):
        for j in range(n):
            summs[j] += a[i][j]
    for elem in summs:
        if elem != summ:
            return False
    diagonals = [0, 0]
    for i in range(n):
        for j in range(n):
            if i == j:
                diagonals[0] += a[i][j]
            if i == n - j - 1:
                diagonals[1] += a[i][j]
    if diagonals[0] != summ or diagonals[1] != summ:
        return False
    return True


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
if n == 1:
    print(1)
else:
    index = [0, 0]
    f = False
    for i in range(n):
        for j in range(n):
            if not a[i][j]:
                index = [i, j]
                f = True
                break
        if f:
            break
    summ = sum(a[index[0] - 1])
    summ2 = sum(a[index[0]])
    ans = summ - summ2
    a[index[0]][index[1]] = ans
    if ans <= 0:
        print(-1)
        exit()
    if test_square(a):
        print(ans)
    else:
        print(-1)