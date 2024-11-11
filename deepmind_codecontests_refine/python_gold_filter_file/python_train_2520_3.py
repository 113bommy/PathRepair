import math
pts, no = input().split()
pts = int(pts)
no = int(no)

x, y = input().split()
x = int(x)
y = int(y)
dist = 0
 
for i in range(pts - 1):
    x1, y1 = input().split()
    x1 = int(x1)
    y1 = int(y1)
    dist += math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))
    x = x1
    y = y1
    
print((dist*no)/50)