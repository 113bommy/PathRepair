n = int(input())

ll = []

for i in range(n):
    ll.append([0] * n)

ll[n//2][n//2] = 1
if n > 1:
    ll[n//2-1][n//2-1] = 2
    ll[n//2-1][n//2] = 3
    ll[n//2-1][n//2+1] = 6
    ll[n//2][n//2-1] = 7
    ll[n//2][n//2+1] = 9
    ll[n//2+1][n//2-1] = 8
    ll[n//2+1][n//2] = 5
    ll[n//2+1][n//2+1] = 4

q = 9
nq = 25
nqq = 5
for i in range(n//2-2, -1, -1):
    ll[i][i] = q+1
    ll[n-1-i][n-1-i] = q+3
    ll[i][n-1-i] = q+5
    ll[n-1-i][i] = q+7
    q += 7
    j = i+1
    while q < nq:
        ll[i][j] = q+2
        ll[n-1-i][j] = q+4
        q += 4
        j += 1
    q = (nqq-2) ** 2
    ll[i][n-2-i] = q+2
    ll[n-1-i][n-2-i] = q+4
    q += 4
    j = i+1
    while q < nq:
        ll[j][i] = q+2
        ll[j][n-1-i] = q+4
        q += 4
        j += 1
    nqq += 2
    nq = nqq ** 2

for i in range(n):
    print(" ".join(map(str, ll[i])))