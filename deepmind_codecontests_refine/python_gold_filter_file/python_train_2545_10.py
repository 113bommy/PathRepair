import sys
import math
import os

x1,y1,x2,y2 = list(map(int, input().split()))
if x1!=x2 and y1!=y2:
    if abs(x1-x2)!=abs(y1-y2):
        print(-1)
    else:
        print(x1,y2,x2,y1)
elif x1==x2:
    print(x1+abs(y2-y1),y1,x1+abs(y2-y1),y2)
else:
    print(x1,y1+abs(x1-x2),x2,y2+abs(x1-x2))