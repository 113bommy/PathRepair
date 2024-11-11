n = int(input())
xx = [[] for _ in range(200001)]
yy = [[] for _ in range(200001)]
xy = [[] for _ in range(400001)]
yx = [[] for _ in range(200001)]
for _ in range(n):
    x, y, u = input().split()
    if u=='U' or u=='D':
        xx[int(x)].append((int(y), u))
    else:
        yy[int(y)].append((int(x), u))
    xy[int(x)+int(y)].append((int(x), u))
    yx[int(y)-int(x)].append((int(x), u))
ans = 10**10
for i in xx:
    if len(i)<=1:
        continue
    i.sort()
    d = -10**10
    for j, k in i:
        if k=='U':
            d = j
        elif ans > (j-d)*5:
            ans = (j-d)*5
for i in yy:
    if len(i)<=1:
        continue
    i.sort()
    d = -10**10
    for j, k in i:
        if k=='R':
            d = j
        elif ans > (j-d)*5:
            ans = (j-d)*5
for i in xy:
    if len(i)<=1:
        continue
    i.sort()
    d = -10**10
    for j, k in i:
        if k=='R':
            d = j
        elif k=='U' and ans > (j-d)*10:
            ans = (j-d)*10
    d = -10**10
    for j, k in i:
        if k=='D':
            d = j
        elif k=='L' and ans > (j-d)*10:
            ans = (j-d)*10
for i in yx:
    if len(i)<=1:
        continue
    i.sort()
    d = -10**10
    for j, k in i:
        if k=='U':
            d = j
        elif k=='L' and ans > (j-d)*10:
            ans = (j-d)*10
    d = -10**10
    for j, k in i:
        if k=='R':
            d = j
        elif k=='D' and ans > (j-d)*10:
            ans = (j-d)*10
if ans == 10**10:
    print('SAFE')
else:
    print(ans)