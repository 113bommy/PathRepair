a, b, c, d = map(int, input().strip().split())

def fill(s, st, ch, cnt):    
    ri, ci = st, 0
    while cnt > 0:
        s[ri][ci] = ch
        cnt -= 1
        ci += 2
        if ci >= 50:
            ri += 3
            ci = 0

dat = dict()
dat.update({'A': a, 'B': b, 'C': c, 'D': d})
dat = sorted(dat.items(), key=lambda kv : kv[1])
mf = dat[3]
lf = dat[0]
res = list()
for i in range(30):
    res.append(list(lf[0] * 50))
for i in range(20):
    res.append(list(mf[0] * 50))
fill(res, 0, dat[3][0], dat[3][1] - 1)
fill(res, 1, dat[2][0], dat[2][1])
fill(res, 2, dat[1][0], dat[1][1])
fill(res, 31, dat[0][0], dat[0][1] - 1)
print(50, 50)
for e_ in res:
    print(''.join(map(str, e_)))