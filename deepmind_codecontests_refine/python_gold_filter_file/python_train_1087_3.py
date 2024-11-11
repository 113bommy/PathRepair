int(input())
aList = sorted([int(x) for x in input().split()])
bList = []
needSecond = False
thing = 0
for i in aList:
  if i < 0 and not needSecond:
    thing = i
    needSecond = True
  elif i < 0:
    bList.append(thing)
    bList.append(i)
    needSecond = False
  elif i > 0:
    bList.append(i)
if len(bList) == 0:
    print(max(aList))
else:
    print(' '.join([str(x) for x in bList]))

