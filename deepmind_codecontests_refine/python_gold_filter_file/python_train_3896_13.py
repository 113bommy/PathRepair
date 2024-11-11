import math
r1, c1, r2, c2 = input().split()
r1 = int(r1)
c1 = int(c1)
r2 = int(r2)
c2 = int(c2)
l = []
if math.fabs(r1 - r2) == 0 or math.fabs(c1 - c2) == 0:
    l.append(1)
else:
    l.append(2)
if math.fabs(r1 - r2) == math.fabs(c1 - c2):
    l.append(1)
elif (r1 + c1) % 2 == (r2 + c2) % 2:
    l.append(2)
else:
    l.append(0)
l.append(int(max(math.fabs(r1 - r2), math.fabs(c1 - c2))))

for i in l:
    print(i, end=" ")