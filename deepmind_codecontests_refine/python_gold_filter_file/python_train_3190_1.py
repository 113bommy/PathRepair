l = [ [ [] for i in range(3)] for i in range(3)]
for i in range(3):
    for j in range(3):
        tmp = list(map(str, input().split(" ")))
        for k in range(3):
            l[k][i] += [tmp[k]]
    if(i != 2):
        input()
y, x = list(map(int, input().split(" ")))
y = y-1
x = x-1
yy = y%3
xx = x%3
f = 0
for i in range(3):
    s = list(l[xx][yy][i])
    for j in range(3):
        if(s[j] == "."):
            s[j] = "!"
            f = 1
    l[xx][yy][i] = "".join(s)
    # print(l[xx][yy][i])
if(f == 0):
    for i in range(3):
        for j in range(3):
            for k in range(3):
                s = list(l[i][j][k])
                for z in range(3):
                    if(s[z] == "."):
                        s[z] = "!"
                l[i][j][k] = "".join(s)
for i in range(3):
    for j in range(3):
        print(l[0][i][j], l[1][i][j], l[2][i][j])
    print()
