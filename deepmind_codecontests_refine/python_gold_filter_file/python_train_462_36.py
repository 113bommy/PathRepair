r, x1, y1, x2, y2 = map(int, input().split())
d = ((x2-x1)**2+(y2-y1)**2)**0.5
if d % (2*r) == 0:
    print(int(d//(2*r)))
else:
    print(int(d//(2*r)+1))
