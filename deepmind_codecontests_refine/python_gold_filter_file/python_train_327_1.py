t = int(input())
for _ in range(t):
    ss = input()
    minx=0
    fminxpos = -1
    lminxpos = -1
    maxx=0
    fmaxxpos = -1
    lmaxxpos = -1
    miny=0
    fminypos = -1
    lminypos = -1
    maxy=0
    fmaxypos = -1
    lmaxypos = -1
    x = 0
    y = 0
    for i,s in enumerate(ss):
        if s == 'W':
            y +=1
            if y > maxy:
                maxy=y
                fmaxypos=i
            if y == maxy:
                lmaxypos=i
        elif s == 'S':
            y -= 1
            if y < miny:
                miny = y
                fminypos = i
            if y == miny:
                lminypos = i
        elif s == 'D':
            lastd = i
            x += 1
            if x > maxx:
                maxx = x
                fmaxxpos = i
            if x == maxx:
                lmaxxpos = i
        elif s == 'A':
            lasta = i
            x -= 1
            if x < minx:
                minx = x
                fminxpos = i
            if x == minx:
                lminxpos = i
    xsize = maxx - minx + 1
    ysize = maxy - miny + 1
    if xsize > 2 and (fmaxxpos > lminxpos or fminxpos > lmaxxpos):
        xmin = xsize - 1
    else:
        xmin = xsize
    if ysize > 2 and (fmaxypos > lminypos or fminypos > lmaxypos):
        ymin = ysize - 1
    else:
        ymin = ysize
    print(min(xmin*ysize, xsize*ymin))