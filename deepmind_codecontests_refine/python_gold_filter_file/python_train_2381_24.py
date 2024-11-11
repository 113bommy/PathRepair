import sys

inputNum = sys.stdin.readlines()

for i in inputNum:
    new = []
    n = i[:-1].split(' ', 6)
    for s in n:
        new.append(float(s))
    k = new[0]
    q = 0
    for a in new[0:3]:
        new[q] = a/k
        q = q + 1
    l = new[3]
    for a in new[3:6]:
        new[q] = a - l*new[q-3]
        q = q + 1
    if new[4] == 0:
        y = new[5]
    else:
        y = new[5]/new[4]
    x = new[2]-(new[1]*y)
    print("{0:.3f}".format(x)+" "+"{0:.3f}".format(y))