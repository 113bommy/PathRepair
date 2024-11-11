import math

x1, y1, x2, y2 = map(int, input().split())
if (x1 == x2) and (y1 == y2):
    print(0, 0, 0)
else:    
    # ladya
    if (x1 == x2) or (y1 == y2):
        l = 1
    else:
        l = 2
    
    #slon
    if (abs(x1 - x2) == abs(y1 - y2)):
        s = 1
    elif ((x1 + y1) % 2 == (x2 + y2) % 2): 
        s = 2
    else:
        s = 0

    #korol
    k = max(abs(x1 - x2), abs(y1 - y2))
    print(l, s, k)