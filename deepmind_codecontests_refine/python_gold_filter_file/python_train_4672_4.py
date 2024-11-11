import math
import sys


def get_triangle_area(x1, y1, x2, y2, x3, y3):
    l1 = math.sqrt(abs(x1-x2)**2+abs(y1-y2)**2)
    l2 = math.sqrt(abs(x2-x3)**2+abs(y2-y3)**2)
    l3 = math.sqrt(abs(x3-x1)**2+abs(y3-y1)**2)
    s = (l1+l2+l3)/2
    return math.sqrt(s*(s-l1)*(s-l2)*(s-l3))


for l in sys.stdin:
    x1, y1, x2, y2, x3, y3, xp, yp = map(float, l.split())
    s1 = get_triangle_area(x1, y1, x2, y2, x3, y3)
    s2 = get_triangle_area(xp, yp, x1, y1, x2, y2)
    s2 += get_triangle_area(xp, yp, x2, y2, x3, y3)
    s2 += get_triangle_area(xp, yp, x3, y3, x1, y1)
    print("YES" if round(s1, 5) == round(s2, 5) else "NO")