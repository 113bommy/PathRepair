n = int(input())
jadval = []
for i in range(n):
    jadval.append([int(x) for x in input().split()])
for i in range(n):
    for j in range(n):
        if jadval[i][j] == 0:
            a = i
            b = j
            break
if a != 0:
    s = sum(jadval[0])
    jadval[a][b] = s-sum(jadval[a])
elif a == 0 and n == 1:
    print(1)
    exit()
else:
    s = sum(jadval[1])
    jadval[a][b] = s-sum(jadval[a])
if jadval[a][b] <= 0:
    print(-1)
    exit()
s = sum(jadval[0])
for i in range(1, n):
    if s != sum(jadval[i]):
        print(-1)
        exit()
for i in range(n):
    q = 0
    for j in range(n):
        q += jadval[j][i]
    if s != q:
        print(-1)
        exit()
q = 0
for i in range(n):
    q += jadval[i][i]
if q != s:
    print(-1)
    exit()
q = 0
for i in range(n):
    q += jadval[i][n-i-1]
if q != s:
    print(-1)
    exit()
print(jadval[a][b])
