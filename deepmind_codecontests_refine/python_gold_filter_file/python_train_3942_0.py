def main():
    def b_search(a, b, value, delta):
        while True:
            med = (a+b)/2
            if abs(b-a) < delta:
                if value(b):
                    return b
                else:
                    return a
            elif value(med):
                a = med
            else:
                b = med

    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    x3, y3 = map(int, input().split())

    a = ((x1-x2)**2+(y1-y2)**2)**0.5
    b = ((x2-x3)**2+(y2-y3)**2)**0.5
    c = ((x3-x1)**2+(y3-y1)**2)**0.5

    m = max(a, b, c)
    if a == m:
        l = a
    elif b == m:
        x1, x2, x3 = x2, x3, x1
        y1, y2, y3 = y2, y3, y1
        l = b
    else:
        x1, x2, x3 = x3, x1, x2
        y1, y2, y3 = y3, y1, y2
        l = c

    x2 -= x1
    x3 -= x1
    y2 -= y1
    y3 -= y1
    x1, y1 = 0, 0

    if x2 < 0:
        x2 = -x2
        x3 = -x3
    if y2 < 0:
        y2 = -y2
        y3 = -y3

    cos = x2/l
    sin = -(1-cos**2)**0.5

    x2, y2 = l, 0
    x3, y3 = abs(cos*x3-sin*y3), abs(sin*x3+cos*y3)

    a = l
    b = (x3**2+y3**2)**0.5
    c = ((x2-x3)**2+(y2-y3)**2)**0.5

    def value(x):
        t1 = x*y3/x3
        t2 = (x2-x)*y3/(x2-x3)
        s1 = t1*x/2
        s2 = t2*(a-x)/2
        r1 = (2*s1)/(x+t1+(x**2+t1**2)**0.5)
        r2 = (2*s2)/((a-x)+t2+((a-x)**2+t2**2)**0.5)
        if r1 < r2:
            return True
        else:
            return False

    def value2(x):
        t1 = x*y3/x3
        s1 = t1*x/2
        r1 = (2*s1)/(x+t1+(x**2+t1**2)**0.5)
        return r1

    v = b_search(0, l, value, 10**(-12))
    print(value2(v))


main()
