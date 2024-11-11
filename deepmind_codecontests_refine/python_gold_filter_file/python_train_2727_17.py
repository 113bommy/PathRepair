MOD = 1000000007
h, w = [int(i) for i in input().split()]
r = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
mat = [[0 for i in range(w)] for j in range(h)]
flag = 0
for i in range(h):
    for j in range(w):
        if r[i] > 0 and c[j] > 0:
            r[i] -= 1
            c[j] -= 1
            mat[i][j] = 3
        elif r[i] > 0 or c[j] > 0:
            if r[i] > 0 and (i != 0 and (mat[i - 1][j] == 0 or mat[i - 1][j] == 1)):
                r[i] -= 1
                mat[i][j] = 1
            elif c[j] > 0 and (j != 0 and (mat[i][j-1] == 0 or mat[i][j-1] == 2)):
                c[j] -= 1
                mat[i][j] = 2
            else:
                flag = 1
count = 1
for i in range(1, h):
    for j in range(1, w):
        if mat[i][j] == 0:
            if (mat[i][j - 1] != 3) and (mat[i][j - 1] != 1):
                if (mat[i - 1][j] != 3) and (mat[i - 1][j] != 2):
                    count = (count * 2) % MOD
if flag == 0:
    #print(mat)
    print(count % MOD)
else:
    print(0)
