x, y = map(int, input().split())

if x > 0 and y > 0:
    x1 = 0
    y1 = x + y
    x2 = y1
    y2 = 0
elif x < 0 and y > 0:
    x, y = abs(x), abs(y)
    x1 = -1 * (x + y)
    y1 = 0
    x2 = 0
    y2 = x + y
elif x < 0 and y < 0:
    x, y = abs(x), abs(y)
    x1 = -1 * (x + y)
    y1 = 0
    x2 = 0
    y2 = x1
else:
    x, y = abs(x), abs(y)
    x1 = 0
    y1 = -1 * (x + y)
    x2 = -1 * y1
    y2 = 0
    
ans = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2)

print (ans)