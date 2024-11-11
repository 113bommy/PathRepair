__author__ = 'mac'

from collections import Counter

def sortByDiag(elem):
        return elem[0]*elem[0]+elem[1]*elem[1]

count = int(input())
points = {}
compList = []
for i in range(count):
    x,y = [int(x) for x in input().strip().split(' ')]
    w = y-x
    compList.append(w)
    if not w in points:
        points[w] = []
    points[w].append([x,y])

wArr = []
for x in input().strip().split(' '):
    if (len(wArr) > 1 and int(x) == wArr[-1]) or (abs(int(x))>len(wArr)):
        print('NO')
        exit()
    wArr.append(int(x))



c1 = Counter(wArr)
c2 = Counter(compList)

diff = c1-c2
if len(list(diff.elements())) != 0:
     print('NO')
     exit()

print('YES')

for e in points:
    points[e] = sorted(points[e], key = sortByDiag)

for i in wArr:
    temp = points[i].pop(0)
    print(temp[0],temp[1])