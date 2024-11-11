import sys

f = int(sys.stdin.readline())
s = str(sys.stdin.readline())
hh, mm = s.split(':')
h1 = int(hh[0])
h2 = int(hh[1])
m1 = int(mm[0])
m2 = int(mm[1])

if f == 12:
    if h1 > 1:
        if h2 < 3:
            h1 = 1
        else:
            h1 = 0
    if h1 == 0 and h2 == 0:
        h2 = 1
    elif h1 == 1:
        if h2 > 2:
            h2 = 1
else:
    if h1 > 2 or (h1 == 2 and h2 > 3):
        h1 = 1

if m1 > 5:
    m1 = 1

print("%d%d:%d%d" % (h1, h2, m1, m2))
