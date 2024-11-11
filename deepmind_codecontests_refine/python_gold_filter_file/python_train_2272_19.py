N,C = [int(i) for i in input().split()]
D = [[int(j) for j in input().split()] for i in range(C)]
c_temp = [[int(j)-1 for j in input().split()] for i in range(N)]
c = [[0 for i in range(C)] for j in range(3)]
for i in range(N):
    for j in range(N):
        c[(i+j)%3][c_temp[i][j]] += 1

min = 10**15
for i in [ii for ii in range(C)]:
    for j in [jj for jj in range(C) if jj != i]:
        for k in [kk for kk in range(C) if kk != i and kk != j]:
            count = sum([D[x][i]*c[0][x] + D[x][j]*c[1][x] + D[x][k]*c[2][x] for x in range(C)])
            if min > count:
                min = count
print(min)


