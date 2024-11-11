import math
input()
vx = [int(i) for i in input().split()]
vy = [int(i) for i in input().split()]

Dxy = []
for p in range(1,4):
    Dxy.append(sum([abs(vx[i] - vy[i]) ** p for i in range(len(vx))]) ** (1 / p))

Dxy.append(max([abs(vx[i] - vy[i]) for i in range(len(vx))]))
for res in Dxy:
    print('{0:.5f}'.format(res))