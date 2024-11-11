na, ma = map(int, input().split())
A = [[0] * 50 for i in range(50)]
for i in range(50 - na, 50):
    t = int(input(), 2)
    for j in range(50):
        A[i][49 - j] = t
        t //= 2   
nb, mb = map(int, input().split())
B = [[0] * 50 for i in range(50)]
for i in range(50 - nb, 50):
    t = int(input(), 2)
    for j in range(50):
        B[i][49 - j] = t
        t //= 2
x, y, ans = 0, 0, -1
for i in range(50):
    for j in range(50):
        s = sum(bin(A[k][j] & B[49 - i + k][49]).count('1') for k in range(i + 1))
        if s > ans:
            ans = s
            x, y = i, j
for i in range(50, 99):
    for j in range(50):
        s = sum(bin(A[k][j] & B[49 - i + k][49]).count('1') for k in range(i - 49, 50))
        if s > ans:
            ans = s
            x, y = i, j
for i in range(50):
    for j in range(50, 99):
        s = sum(bin(A[k][49] & B[49 - i + k][98 - j]).count('1') for k in range(i + 1))
        if s > ans:
            ans = s
            x, y = i, j
for i in range(50, 99):
    for j in range(50, 99):
        s = sum(bin(A[k][49] & B[49 - i + k][98 - j]).count('1') for k in range(i - 49, 50))
        if s > ans:
            ans = s
            x, y = i, j
print(49 - x + nb - na, 49 - y + mb - ma)