while True:
    try:
        a,b,c,d,e,f=[float(i) for i in input().split()]
    except:
        break
    x=(c*e-b*f)/(a*e-b*d)
    y=(c*d-a*f)/(b*d-a*e)
    print("{0:.3f} {1:.3f}".format(x+0,y+0))