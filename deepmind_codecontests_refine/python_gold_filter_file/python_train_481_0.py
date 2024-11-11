from operator import itemgetter
import sys
input = sys.stdin.buffer.readline


def _mul(A, B, MOD):
    C = [[0] * len(B[0]) for i in range(len(A))]
    for i in range(len(A)):
        for k in range(len(B)):
            for j in range(len(B[0])):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
    return C


def pow_matrix(A, n, MOD):
    B = [[0] * len(A) for i in range(len(A))]
    for i in range(len(A)):
        B[i][i] = 1
    while n > 0:
        if n & 1:
            B = _mul(A, B, MOD)
        A = _mul(A, A, MOD)
        n  = n // 2
    return B


def calc(A, vec, MOD):
    n = len(vec)
    res = [0] * n
    for i in range(n):
        for j in range(n):
            res[i] += A[i][j] * vec[j]
            res[i] %= MOD
    return res

n, m = map(int, input().split())
info = [list(map(int, input().split())) for i in range(n)]
MOD = 10 ** 9 + 7


res = [[] for i in range(3)]
for row, l, r in info:
    row -= 1
    l -= 1
    res[row].append((l, r))
for row in range(3):
    res[row].sort(key=itemgetter(1))

blocks = {}
ind_set = set([])
for row in range(3):
    tmp = []
    for l, r in res[row]:
        if not tmp:
            tmp.append((l, r))
            continue
        while tmp:
            if l <= tmp[-1][1]:
                pl, pr = tmp.pop()
                l = min(pl, l)
            else:
                break
        tmp.append((l, r))
    for l, r in tmp:
        if l not in blocks:
            blocks[l] = []
        if r not in blocks:
            blocks[r] = []
        blocks[l].append((row, 1))
        blocks[r].append((row, -1))
        ind_set.add(l)
        ind_set.add(r)

ind_list = sorted(list(ind_set))

dp = [0, 1, 0]
matrix = [[1, 1, 0], [1, 1, 1], [0, 1, 1]]

prv_ind = 0
for ind in ind_list:
    length = (ind - prv_ind - 1)
    tmp_matrix = pow_matrix(matrix, length, MOD)
    dp = calc(tmp_matrix, dp, MOD)
    
    for row, flag in blocks[ind]:
        if flag == 1:
            for i in range(3):
                matrix[row][i] = 0
        else:
            for i in range(3):
                matrix[row][i] = 1
            matrix[0][2] = 0
            matrix[2][0] = 0
    dp = calc(matrix, dp, MOD)
    prv_ind = ind

length = m - prv_ind - 1
tmp_matrix = pow_matrix(matrix, length, MOD)
dp = calc(tmp_matrix, dp, MOD)

print(dp[1] % MOD)