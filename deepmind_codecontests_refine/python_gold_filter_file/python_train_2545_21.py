x1, y1, x2, y2 = list(map(int,input().split()))
if x1 == x2 :
    d = abs(y2-y1)
    x3 , y3 = x2+d , y2
    x4 , y4 = x1+d , y1
    print("{x3} {y3} {x4} {y4}".format(x3=x3, y3=y3, x4=x4, y4=y4))
elif y1 == y2:
    d = abs(x2-x1)
    x3 , y3 = x2 , y2+d
    x4 , y4 = x1 , y1+d
    print("{x3} {y3} {x4} {y4}".format(x3=x3, y3=y3, x4=x4, y4=y4))
else:
    d = abs(x2-x1)
    true_dist = (x2-x1)**2 + (y2-y1)**2
    apparent_dist = 2*(d**2)
    if true_dist == apparent_dist:
        if min(y1,y2) == y1:
            dist = x2-x1
            x3, y3 = x1 + dist, y1
            x4, y4 = x2 - dist, y2
            print("{x3} {y3} {x4} {y4}".format(x3=x3, y3=y3, x4=x4, y4=y4))
        else:
            dist = x1-x2
            x3, y3 = x2 + dist, y2
            x4, y4 = x1 - dist, y1
            print("{x3} {y3} {x4} {y4}".format(x3=x3, y3=y3, x4=x4, y4=y4))
    else:
        print(-1)