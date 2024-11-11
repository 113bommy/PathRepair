while True:
    try:
        a, b, c, d, e, f = map(float, input().split())
        x = (c*e - b*f)/(a*e - b*d)
        y = (f*a - c*d)/(a*e - d*b)
        print( "{0:.3f} {1:.3f}".format(x+0, y+0))
    except:
        break