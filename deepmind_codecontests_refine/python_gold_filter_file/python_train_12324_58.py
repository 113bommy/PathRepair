def getXValue():
    n = int(input())
    instructionList = []
    X = 0
    for i in range(n):
        instructionList.append(input().upper())

    for instruction in instructionList:
        instruct = [chars for chars in instruction]
        for chars in instruct:
            if chars == '+':
                X += 1
                break
            elif chars == '-':
                X -= 1
                break
    return X


print(getXValue())
