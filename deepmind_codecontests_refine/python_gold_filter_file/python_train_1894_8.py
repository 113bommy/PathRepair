returnList = []

length = int(input())

tempLength = length

tempList = []

while(tempLength>0):
    tempLength -= 1
    number = int(input())
    numbers = input().split()

    for x in numbers:
        x = int(x)
        tempList.append(x)

    tempList.sort(reverse=True)

    counter = 0

    for x in tempList:
        if (x >= 4096):
            continue
        counter += x
        if(counter == 2048):
            returnList.append("YES")
            break

    if(counter!=2048):
        returnList.append("NO")

    tempList.clear()
for x in returnList:
    print("{}".format(x))
