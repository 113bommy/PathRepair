n=int(input())
for i in range(n):
    m=int(input())
    v = [[0 for k in range(m)] for kk in range(m)]
    for j in range(m):
        v[j][j] = 9
        v[j][j-1] = 4
    for i in range(m):
        print(*v[i])


