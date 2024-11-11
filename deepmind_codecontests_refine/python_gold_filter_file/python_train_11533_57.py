h,w = map(int,input().split())
ch, cw = map(int,input().split())
dh, dw = map(int,input().split())
s = [list(input()) for _ in range(h)]
ch -= 1
cw -= 1
dh -= 1
dw -= 1
vec5 = []
vec = [(1, 0), (0, 1), (-1, 0), (0, -1)]
for i in range(-2, 3):
    for j in range(-2, 3):
        if abs(i) + abs(j) < 2:
            continue
        vec5 += [(i,j)]

c = 0
q = [(ch, cw)]
while len(q) > 0:
    nq = []
    while len(q) > 0:
        i, j = q.pop()
        s[i][j] = c
        nq += [(i,j)]
        for v in vec:
            ii = i + v[0]
            jj = j + v[1]
            if 0 <= ii < h and 0 <= jj < w and s[ii][jj] == '.':
                q += [(ii, jj)]


    while len(nq) > 0:
        i, j = nq.pop()
        for v in vec5:
            ii = i+v[0]
            jj = j+v[1]
            if 0 <= ii < h and 0 <= jj < w and s[ii][jj] == '.':
                q += [(ii, jj)]
    c += 1
if s[dh][dw] == '.':
    print(-1)
else:
    print(s[dh][dw])
