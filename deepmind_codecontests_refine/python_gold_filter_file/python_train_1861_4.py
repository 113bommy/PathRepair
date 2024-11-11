import math
deg = 90
x = 0.0
y = 0.0
while True:
    di,ai = map(int, input().split(','))
    if di==0 and ai==0:
        break
    x += di*math.cos(deg*math.pi/180.0)
    y += di*math.sin(deg*math.pi/180.0)
    deg -= ai

print("%d\n%d" % (x,y))