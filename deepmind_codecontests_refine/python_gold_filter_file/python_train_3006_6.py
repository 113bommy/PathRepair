import sys
import math
n = int(sys.stdin.readline().rstrip())
for i in range(n):
    x1,y1,x2,y2,x3,y3 = map(float, sys.stdin.readline().rstrip().split(' '))
    p = ((y1-y3)*(y1**2-y2**2+x1**2-x2**2)-(y1-y2)*(y1**2-y3**2+x1**2-x3**2)) / (2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3))
    q = ((x1-x3)*(x1**2-x2**2+y1**2-y2**2)-(x1-x2)*(x1**2-x3**2+y1**2-y3**2)) / (2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3))
    r = math.sqrt((p-x1)**2 + (q-y1)**2)
    print("{:0.3f} {:0.3f} {:0.3f}".format(round(p,3),round(q,3),round(r,3)))