n, T = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
tp, tm = [], []
s = 0
for i, x in enumerate(input().split()):
    dt = int(x)-T
    if dt > 0:
        tp.append([dt, a[i]])
    elif dt < 0:
        tm.append([-dt, a[i]])
    else:
        s+=a[i]

tp.sort()
tm.sort()
i,j= 0, 0
while i < len(tp) and j < len(tm):
    qp = tp[i][0]*tp[i][1]
    qm = tm[j][0]*tm[j][1]
    if qp>qm:
        r = tm[j][0]/tp[i][0]
        s += (1+r)*tm[j][1]
        tp[i][1] -= tm[j][1]*r
        j += 1
    else:
        r = tp[i][0]/tm[j][0]
        s += (1+r)*tp[i][1]
        tm[j][1] -= tp[i][1]*r
        i += 1
print(s)
