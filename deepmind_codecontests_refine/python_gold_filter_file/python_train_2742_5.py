def l(vx ,vy):
    return (vx*vx+vy*vy)

x1,y1,x2,y2,x3,y3 = [int (i) for i in input().split()]

ax = x2-x1
ay = y2-y1
bx = x3-x2
by = y3-y2
cx = x1-x3
cy = y1-y3

la = l(ax,ay)
lb = l(bx,by)
lc = l(cx,cy)

lb,lc = max(lb,lc),min(lb,lc)
la,lb = max(la,lb),min(la,lb)

if la == lb+lc :
    print ('RIGHT')
else:
    f = False
    vs = [ax,ay,bx,by,cx,cy,ax,ay]
    for i in range(6):
        for j in [-1,1]:
            vs[i] += j
            vs[i+2] -= j
            if i>3:
                vs[0] = vs[6]
                vs[1] = vs[7]
            la = l(vs[0], vs[1])
            lb = l(vs[2], vs[3])
            lc = l(vs[4], vs[5])

            lb, lc = max(lb, lc), min(lb, lc)
            la, lb = max(la, lb), min(la, lb)

            if (la == lb+lc) and (la*lb*lc!=0):
                print ('ALMOST')
                f = True
                break
            vs[i] -= j
            vs[i + 2] += j
            if i>3:
                vs[0] = vs[6]
                vs[1] = vs[7]
        if f:
            break
    if not f:
        print ('NEITHER')

