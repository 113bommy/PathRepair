import sys
for line in sys.stdin:
    a,b,c,d,e,f = map(int,line.strip().split(' '))
    x = (c*e - b*f) / (a*e - b*d)
    y = (c*d - a*f) / (b*d - a*e)
    print("{:.3f} {:.3f}".format(x+0, y+0))