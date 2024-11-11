l1 = input().split(' ')
n = int(l1[0])
t = int(l1[1])
c = int(l1[2])
ways = 0
arr = []
l2 = input().split(' ')

for a in l2:
    arr.append(int(a))

cut = [0]
for j in range(len(arr)):
    sever = arr[j]
    if sever > t:
        cut.append(j)
cut.append(len(arr)-1)
import math
if len(cut) == 2:
    if len(arr)>=c:
        ways += len(arr)-c+1
    else:
        ways = 0
else:
    for d in range(len(cut)-1):
        ele1 = cut[d]
        ele2 = cut[d+1]
        if d == 0 or d == len(cut)-2:
            if ele2-ele1>=c:
                ways += ((ele2 - ele1)-c +1)
        else:
            diff = ele2-ele1 - 1
            if diff >= c:
                ways += (diff - c + 1)
        
print(ways)
#11 4 2
#2 2 0 7 3 2 2 4 9 1 4
#0 3 8 10
#2 2, 2 0, 3 2, 2 2, 2 4, 1 4