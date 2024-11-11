import math
import sys

xy=[]
for i in range(3):
    xy.append(list(map(int,input().split())))

print(3)
v=[[xy[2][0]-xy[1][0],xy[2][1]-xy[1][1]],
   [xy[0][0]-xy[2][0],xy[0][1]-xy[2][1]],
   [xy[1][0]-xy[0][0],xy[1][1]-xy[0][1]]]

for i in range(3):
    print(xy[i][0]+v[i][0],xy[i][1]+v[i][1])