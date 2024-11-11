import sys
import math

def dist(a, b):
    return math.sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]))

def samep(a, b):
    EPS = 0.00001
    if a - b < -EPS or a - b > EPS:
        return False
    return True

def same(a, b):
    return samep(a[0], b[0]) and samep(a[1], b[1])

def stat(a, tata):
    if tata[a] == a:
        return a
    x = stat(tata[a], tata)
    tata[a] = x
    return x

def unesc(a, b, tata):
    y = stat(b, tata)
    x = stat(a, tata)
    if x != y:
        tata[x] = y
    return

#fin = open('cerc.in', 'r')
#fout = open('cerc.out', 'w')
fin = sys.stdin
fout = sys.stdout
n = int(fin.readline())
a = []
for i in range(0, n):
    a.append(tuple([int(number) for number in fin.readline().split()]))
#find V
pnt = []
pntc = []
for i in range(0, n):
    for j in range(i + 1, n):
        if (a[i][0] != a[j][0] or a[i][1] != a[j][1]):
            a0, a1, a2 = a[i]
            b0, b1, b2 = a[j]
            c0 = 2 * (b0 - a0)
            c1 = 2 * (b1 - a1)
            c2 = -a0 * a0 + -a1 * a1 + a2 * a2 + b0 * b0 + b1 * b1 - b2 * b2
            npoints = []
            if c0 == 0:
                y0 = c2 / c1
                x1 = a2 * a2 - (y0 - a1) * (y0 - a1)
                x0 = math.sqrt(x1)
                npoints.append((-x0 + a0, y0))
                npoints.append((x0 + a0, y0))
            else:
                d0 = -c1 / c0
                d1 = c2 / c0
                e0 = (d0 * d0 + 1)
                e1 = 2 * d0 * (d1 - a0) - 2 * a1
                e2 = (d1 - a0) * (d1 - a0) + a1 * a1 - a2 * a2
                dt = e1 * e1 - 4 * e2 * e0
                if dt >= -0.000001 and dt <= 0.000001:
                    y0 = -e1 / (2 * e0)
                    x0 = d0 * y0 + d1
                    npoints.append((x0, y0))
                elif dt > 0:
                    y0 = (-e1 - math.sqrt(dt)) / (2 * e0)
                    y1 = (-e1 + math.sqrt(dt)) / (2 * e0)
                    x0 = d0 * y0 + d1
                    x1 = d0 * y1 + d1
                    npoints.append((x0, y0))
                    npoints.append((x1, y1))
            for np in npoints:
                g = 0
                for poz in range(0, len(pnt)):
                    if same(pnt[poz], np):
                        g = 1
                        pntc[poz].add(i)
                        pntc[poz].add(j)
                        break
                if g == 0:
                    pnt.append(np)
                    pntc.append(set({i, j}))
pntc = [list(x) for x in pntc]
V = len(pnt)
#find C
tata = list(range(0, n))
C = 1
for p in range(0, V):
    for i in range(0, len(pntc[p])):
        for j in range(i + 1, len(pntc[p])):
            unesc(pntc[p][i], pntc[p][j], tata)
for p in range(0, n):
    if tata[p] == p:
        C += 1
#find E
E = 0
for p in range(0, V):
    for x in pntc[p]:
        E += 1
F = E + C - V
fout.write(repr(F))
if fin != sys.stdin:
    fin.close()
    fout.close()
