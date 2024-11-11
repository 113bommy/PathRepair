import math
n = int(input())
groups = list(map(int, input().split()))
x1, x2, x3, x4 = 0, 0, 0, 0
for i in groups:
    if i == 1:
        x1 += 1
    elif i == 2:
        x2 += 1
    elif i == 3:
        x3 += 1
    else:
        x4 += 1
if x3 >= x1:
    print(x4+x3+math.ceil(x2/2))
else:
    r1 = x1 - x3
    l1 = r1 - (4*math.ceil(x2/2)-x2*2)
    if l1 > 0:
        print(math.ceil(l1/4)+math.ceil(x2/2)+x3+x4)
    else:
        print(math.ceil(x2/2)+x3+x4)
