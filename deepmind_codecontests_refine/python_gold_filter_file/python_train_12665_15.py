import math
n,k = map(int, input().split())
b = [list(input()) for _ in range(n)]
c = [[0]*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if b[i][j] == '.':
            if i+k <= n:
                f = True
                for z in range(1, k):
                    if b[i+z][j] != '.':
                        f = False
                        break
                if f:
                    for z in range(0, k):
                        c[i+z][j] +=1
            if j +k <= n:
                f = True
                for z in range(1, k):
                    if b[i][j+z] != '.':
                        f = False
                        break
                if f:
                    for z in range(0, k):
                        c[i][j+z] +=1

m = [0, 0]
for i in range(n):
    for j in range(n):
        if c[i][j] > c[m[0]][m[1]]:
            m = [i, j]
print('%i %i' % (m[0] + 1, m[1]+ 1))