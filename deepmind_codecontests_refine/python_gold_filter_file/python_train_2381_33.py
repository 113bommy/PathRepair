import math
import itertools

while 1:
    try:
        a, b, c, d, e, f = map(int, input().split())
        print('{0:.3f} {1:.3f}'.format((e*c-b*f)/(a*e-b*d)+0, (-d*c+a*f)/(a*e-b*d)+0))
    except:
        break