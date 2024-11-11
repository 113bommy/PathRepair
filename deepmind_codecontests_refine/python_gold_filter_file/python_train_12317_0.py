import sys


def putin():
    return map(int, sys.stdin.readline().split())


def f(n):
    return ((3 * n + 1) * 2 ** n - (-1) ** n) // 9


def sol():
    n, k = putin()
    A = []
    for i in range(n):
        A.append(list(sys.stdin.readline()))
    O_number = 0
    for i in range(n):
        for j in range(k):
            O_number += A[i][j] == 'o'
    Red = {}
    for i in range(n):
        cur = int(A[i][0] == 'o')
        for j in range(1, k):
            if A[i][j] == 'o':
                if cur > 0:
                    cur += 1
                else:
                    cur += 1
            else:
                if cur > 0:
                    if cur in Red:
                        Red[cur] += 1
                    else:
                        Red[cur] = 1
                    cur = 0
        if cur > 0:
            if cur in Red:
                Red[cur] += 1
            else:
                Red[cur] = 1

    Blue = {}
    for i in range(k):
        cur = int(A[0][i] == 'o')
        for j in range(1, n):
            if A[j][i] == 'o':
                if cur > 0:
                    cur += 1
                else:
                    cur += 1
            else:
                if cur > 0:
                    if cur in Blue:
                        Blue[cur] += 1
                    else:
                        Blue[cur] = 1
                    cur = 0
        if cur > 0:
            if cur in Blue:
                Blue[cur] += 1
            else:
                Blue[cur] = 1

    answer = 0
    for elem in Red:
        answer += f(elem - 1) * Red[elem] * 2 ** (O_number - elem)
    for elem in Blue:
        answer += f(elem - 1) * Blue[elem] * 2 ** (O_number - elem)
    sys.stdout.write(str(answer % 998244353))


sol()
