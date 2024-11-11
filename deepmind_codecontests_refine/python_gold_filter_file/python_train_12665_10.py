n, k = [int(i) for i in input().split()]
B = [input() for _ in range(n)]
C = [[0]*n for _ in range(n)]

for i in range(n):
    for j in range(n-k+1):
        for l in range(j, j+k):
            if B[i][l] == '#':
                break
        else:
            for l in range(j, j+k):
                C[i][l] += 1

for j in range(n):
    for i in range(n-k+1):
        for l in range(i, i+k):
            if B[l][j] == '#':
                break
        else:
            for l in range(i, i+k):
                C[l][j] += 1

cmax = 0
imax = jmax = 0
for i in range(n):
    for j in range(n):
        if C[i][j] > cmax:
            cmax = C[i][j]
            imax, jmax = i, j

print(imax+1, jmax+1)
