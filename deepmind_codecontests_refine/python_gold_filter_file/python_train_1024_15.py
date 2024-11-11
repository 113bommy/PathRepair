n,m = map(int,input().split())
INF = 10**18
d = [[INF]*n for _ in range(n)]
for i in range(n): d[i][i] = 0
A = [0]*m
B = [0]*m
C = [0]*m
for i in range(m):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    A[i] = a
    B[i] = b
    C[i] = c
    d[a][b] = c
    d[b][a] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k]+d[k][j])

ans = 0
for i in range(m):
    if d[A[i]][B[i]] < C[i]: ans += 1
print(ans)