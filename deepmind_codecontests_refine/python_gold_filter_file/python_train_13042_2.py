for _ in range(int(input())):
    m, n = map(int, input().split())
    A = [[0] * (n + 1)] + [[0] + list(map(int, list(input()))) for _ in range(m)]
    ans = []
    for i in range(1, m - 1):
        for j in range(1, n + 1):
            if A[i][j]:
                ans.append([i, j, i + 1, j, i + 1, j + 1 if j < n else j - 1])
                A[i][j] ^= 1
                A[i + 1][j] ^= 1
                A[i + 1][j + 1 if j < n else j - 1] ^= 1
    for j in range(1, n - 1):
        if A[m - 1][j] and A[m][j]:
            ans.append([m - 1, j, m, j, m - 1, j + 1])
            A[m - 1][j] ^= 1
            A[m][j] ^= 1
            A[m - 1][j + 1] ^= 1
        elif A[m - 1][j]:
            ans.append([m - 1, j, m - 1, j + 1, m, j + 1])
            A[m - 1][j] ^= 1
            A[m - 1][j + 1] ^= 1
            A[m][j + 1] ^= 1
        elif A[m][j]:
            ans.append([m, j, m, j + 1, m - 1, j + 1])
            A[m][j] ^= 1
            A[m][j + 1] ^= 1
            A[m - 1][j + 1] ^= 1
    if A[m - 1][n - 1] ^ A[m - 1][n] ^ A[m][n - 1]:
        ans.append([m - 1, n - 1, m - 1, n, m, n - 1])
    if A[m - 1][n - 1] ^ A[m][n - 1] ^ A[m][n]:
        ans.append([m - 1, n - 1, m, n - 1, m, n])
    if A[m][n - 1] ^ A[m][n] ^ A[m - 1][n]:
        ans.append([m, n - 1, m, n, m - 1, n])
    if A[m][n] ^ A[m - 1][n] ^ A[m - 1][n - 1]:
        ans.append([m, n, m - 1, n, m - 1, n - 1])
    print(len(ans))
    for a in ans: print(*a)