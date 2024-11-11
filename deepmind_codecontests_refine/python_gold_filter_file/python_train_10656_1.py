el = int(input())
minValue = 0
maxValue = 0
minSet = set()
maxSet = set()
ch = 0
for i in range(el):
    temp = []
    for j in input().split(' '):
        temp.append(int(j))
    if ch != 0:
        if temp[0] < minValue:
            minValue = temp[0]
            minSet = set()
            minSet.add(i+1)
        elif temp[0] == minValue:
            minSet.add(i+1)
        if temp[1] > maxValue:
            maxValue = temp[1]
            maxSet = set()
            maxSet.add(i+1)
        elif temp[1] == maxValue:
            maxSet.add(i+1)
    else:
        minValue = temp[0]
        maxValue = temp[1]
        minSet.add(i+1)
        maxSet.add(i+1)
        ch = 1
res = minSet & maxSet
if len(res) == 0:
    print(-1)
else:
    print(list(res)[0])
