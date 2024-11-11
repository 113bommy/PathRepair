def Crossword():
    CList = []
    SStr = []
    TStr = []
    IPT = input()
    iPT = IPT.split()
    s = int(iPT[0])
    t = int(iPT[1])
    minChange = s
    sStr = input()
    tStr = input()
    for x in sStr:
        SStr.append(x)
    for y in tStr:
        TStr.append(y)
    for i in range(t-s+1):
        tempChange = s
        clist = []
        for j in range(i,i+s):
            if (TStr[j] == SStr[j-i]):
                tempChange -= 1
            else:
                clist.append(j-i)
        if tempChange <= minChange:
            minChange = tempChange
            CList = []
            for k in clist:
                CList.append(k)
    print(minChange)
    for x in CList:
        print(x+1, end=" ")

Crossword()