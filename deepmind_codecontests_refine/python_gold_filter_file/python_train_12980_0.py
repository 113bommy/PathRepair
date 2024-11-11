n = int(input())
a = list(map(lambda x: int(x), input().split()))
b = [[0 for j in range(n)] for i in range(n)]

for i in range(n):
    b[0][i] = a[i]

for i in range(1, n):
    for j in range(n-i):
        b[i][j]=b[i-1][j]^b[i-1][j+1]

for i in range(1, n):
    for j in range(n-i):
        pp=max(b[i-1][j],b[i-1][j+1])
        b[i][j]=max(b[i][j],pp)

q = int(input())

for i in range(q):
    l, r = input().split()
    l = int(l)
    r = int(r)
    print(b[r-l][l-1])
