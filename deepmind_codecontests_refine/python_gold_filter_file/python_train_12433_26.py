global xcount
global ocount
import sys
tlist = []
xcount = 0
ocount = 0
countperiod = 0
def finalcheckx():
    global xcount
    global ocount
    for y in range(len(tlist)):
        if xcount <= ocount:
            print('illegal')
            sys.exit()
        elif tlist[0][y] == tlist[1][y] == tlist[2][y]:
            if tlist[0][y] == '0':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[0][0] == tlist[1][1] == tlist[2][2]:
            if tlist[0][0] == '0':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[0][2] == tlist[1][1] == tlist[2][0]:
            if tlist[0][2] == '0':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[y][0] == tlist[y][1] == tlist[y][2]:
            if tlist[y][0] == '0':
                print('illegal')
                sys.exit()
            else:
                continue
        else:
            continue
    print('the first player won')
    sys.exit()
    
def finalchecko():
    global xcount
    global ocount
    for y in range(len(tlist)):
        if xcount > ocount:
            print('illegal')
            sys.exit()
        elif tlist[0][y] == tlist[1][y] == tlist[2][y]:
            if tlist[0][y] == 'X':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[0][0] == tlist[1][1] == tlist[2][2]:
            if tlist[0][0] == 'X':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[0][2] == tlist[1][1] == tlist[2][0]:
            if tlist[0][2] == 'X':
                print('illegal')
                sys.exit()
            else:
                continue
        elif tlist[y][0] == tlist[y][1] == tlist[y][2]:
            if tlist[y][0] == 'X':
                print('illegal')
                sys.exit()
            else:
                continue
        else:
            continue
    print('the second player won')    
    sys.exit()
    
for x in range(3):
    tlist.append(input())

for z in tlist:
    xcount += z.count('X')
    ocount += z.count('0')
if xcount > 5 or ocount > xcount or (ocount + 1) != xcount and ocount != xcount:
    print('illegal')
    sys.exit()

for y in range(len(tlist)):
    if tlist[0][y] == tlist[1][y] == tlist[2][y]:
        if tlist[0][y] == 'X':
            finalcheckx()
        elif tlist[0][y] == '0':
            finalchecko()
        else:
            continue
    elif tlist[0][0] == tlist[1][1] == tlist[2][2]:
        if tlist[0][0] == 'X':
            finalcheckx()
        elif tlist[0][0] == '0':
            finalchecko()
        else:
            continue
    elif tlist[0][2] == tlist[1][1] == tlist[2][0]:
        if tlist[0][2] == 'X':
            finalcheckx()
        elif tlist[0][2] == '0':
            print('the second player won')
            sys.exit()
        else:
            continue
    elif tlist[y][0] == tlist[y][1] == tlist[y][2]:
        if tlist[y][0] == 'X':
            finalcheckx()
        elif tlist[y][0] == '0':
            finalchecko()
        else:
            continue
    else:
        continue
for another in tlist:
    countperiod += another.count('.')
if countperiod == 0:
    print('draw')
    sys.exit()
if xcount > ocount:
    print('second')
    sys.exit()
elif xcount == ocount:
    print('first')
    sys.exit()



    
