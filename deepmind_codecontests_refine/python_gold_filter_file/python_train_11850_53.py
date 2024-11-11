iN,iM = [int(_) for _ in input().split()]

if iM % iN == 0:
    print(iM // iN)
else:
    aRet = []
    for i in range(1,iM//iN + 1):
        if iM % i == 0:
            aRet.append(i)
    print(aRet[-1])
