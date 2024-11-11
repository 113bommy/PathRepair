import sys

x = int(input())

mat = []
sums = [0] * x
r = 0
c = 0
for i in range(x):
    a = list(map(int, sys.stdin.readline().split()))
    mat.append(a)
    sums[i] = sum(a)
    for j in range(x):
        if mat[i][j] == 0:
            r = i
            c = j

if r == 0:
    if x == 1:
        ans = 1
    else:
        ans = sums[1] - sums[r]
else:
    ans = sums[0] - sums[r]

mat[r][c] = ans
ok = True
if ans <= 0:
    ok = False

#print(ok)

if ok:
    s = sum(mat[0])
    for i in range(x):
        si = sum(mat[i])
        if si != s:
            #print('row')
            ok = False
            break

if ok:
    for i in range(x):
        si = 0
        for j in range(x):
            si += mat[j][i]
        if si != s:
            ok = False
            #print('col')
            break

if ok:
    si = 0
    for i in range(x):
        si += mat[i][i]
    if si != s:
        #print('x1')
        ok = False

if ok:
    si = 0
    for i in range(x):
        si += mat[i][x-i-1]
    if si != s:
        #print('x2')
        ok = False

if ok:
    print(ans)
else:
    print(-1)
