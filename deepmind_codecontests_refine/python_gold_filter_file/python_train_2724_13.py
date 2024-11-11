def cal(a, b, i, j):
    if min(a, b, i, j) < 0:
        return 0
    if a == 0 and b == 0:
        return 1
    v = (a, b, i, j)
    if not v in M:
        M[v] = (cal(a-1, b, i-1, y) + cal(a, b-1, x, j-1))%10**8
    return M[v]
n, m, x, y = map(int, input().split())
M = {}
print(cal(n, m, x, y))
