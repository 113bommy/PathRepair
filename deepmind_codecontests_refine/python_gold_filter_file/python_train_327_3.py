T = int(input())

for _ in range(T):
    cmd = input()

    mostL, mostR, mostB, mostT = 0, 0, 0, 0
    mostLs, mostRs, mostBs, mostTs = [0],[0],[0],[0]
    x,y=0,0
    i = 0
    for c in cmd:
        i += 1
        if c == "W":
            y += 1
            if y>mostT:
                mostT = y
                mostTs = [i]
            elif y == mostT:
                mostTs.append(i)
        elif c == "S":
            y -= 1
            if y<mostB:
                mostB = y
                mostBs = [i]
            elif y == mostB:
                mostBs.append(i)
        elif c == "A":
            x -= 1
            if x < mostL:
                mostL = x
                mostLs = [i]
            elif x == mostL:
                mostLs.append(i)
        elif c == "D":
            x += 1
            if x > mostR:
                mostR = x
                mostRs = [i]
            elif x == mostR:
                mostRs.append(i)

    LR = mostR - mostL + 1
    if LR >= 3:
        firstL, lastL = mostLs[0], mostLs[-1]
        firstR, lastR = mostRs[0], mostRs[-1]

        cross = lastR > firstL and lastL > firstR
        LR_extra = not cross
    else:
        LR_extra = False

    BT = mostT - mostB + 1
    if BT >= 3:
        firstB, lastB = mostBs[0], mostBs[-1]
        firstT, lastT = mostTs[0], mostTs[-1]

        cross = lastB > firstT and lastT > firstB
        BT_extra = not cross
    else:
        BT_extra = False

    if LR_extra and BT_extra:
        area = min((LR-1)*BT,LR*(BT-1))
    elif LR_extra:
        area = (LR-1)*BT
    elif BT_extra:
        area = LR*(BT-1)
    else:
        area = LR*BT
    print(area)