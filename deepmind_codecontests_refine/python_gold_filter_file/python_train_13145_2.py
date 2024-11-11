t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    c = [int(i) for i in input().split()]

    if x <= 0 and y >= 0:
        x = abs(x)
        y = abs(y)
        buf = c[2]*x + c[1]*y
        buf = min(buf, x*c[3]+(x + y) * c[1])
        buf = min(buf, y*c[0] + (x + y) * c[2])
        print(buf)

    elif x <= 0 and y <= 0:
        x = abs(x)
        y = abs(y)
        buf = c[2]*x + c[4]*y
        if x <= y:
            buf = min(buf, c[3]*x + (y-x)*c[4])
            buf = min(buf, c[3]*y + (y-x)*c[5])
        else:
            buf = min(buf, c[3]*y + (x-y)*c[2])
            buf = min(buf, c[3]*x + (x-y)*c[1])
        print(buf)
    elif x >= 0 and y >= 0:
        x = abs(x)
        y = abs(y)
        buf = c[5]*x + c[1]*y
        if x <= y:
            buf = min(buf, c[0]*x + (y-x)*c[1])
            buf = min(buf, c[0]*y + (y-x)*c[2])
        else:
            buf = min(buf, c[0]*y + (x - y)*c[5])
            buf = min(buf, c[0]*x + (x - y)*c[4])
        print(buf)
    else:
        x = abs(x)
        y = abs(y)
        buf = c[5]*x + c[4]*y
        buf = min(buf, c[0]*x + (y+x)*c[4])
        buf = min(buf, c[3]*y + (x+y)*c[5])
        print(buf)
