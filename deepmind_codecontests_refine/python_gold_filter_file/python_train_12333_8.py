# map(int, input().split())
import math
def getKey(item):
    return item[1]

n, r, avg  = map(int, input().split())

score = 0
l  = []

for i in range(n):
    a, b = map(int, input().split())
    score+= a
    if a <r:
        l.append([a, b])


essays= 0

needed = n* avg - score

if needed <= 0:
    print(essays)
else:
    l = sorted(l, key= getKey)
    for i in l:
        points = r - i[0]
        if needed >= points:
            essays += (points* i[1])
            needed-= points
        else:
            essays+= (needed * i[1])
            needed= 0
            break
    print(essays)