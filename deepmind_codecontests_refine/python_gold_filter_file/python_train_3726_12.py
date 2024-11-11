# 解説AC
from math import sin, sqrt

N = int(input())
XY = [[int(i) for i in input().split()] for _ in range(N)]

INF = 10 ** 6

def circumcenter(i,j,k):
    """ 3点を通る円の中心(外心) """
    a,b = XY[i]
    c,d = XY[j]
    e,f = XY[k]

    aa, bb, cc, dd, ee, ff = a**2, b**2, c**2, d**2, e**2, f**2

    try:
        y = ((e - a) * (aa + bb - cc - dd) - (c - a) * (aa + bb - ee- ff)) / (2 * (e - a)*(b - d) - 2 * (c - a) * (b - f))
        x = (2 * (b - f) * y - aa - bb + ee + ff) / (2 * (e - a)) if (c == a) else (2 * (b - d) * y - aa - bb + cc + dd) / (2 * (c - a))
    except ZeroDivisionError as e:
        return (-INF, -INF)

    return (x,y)

def radius(x,y):
    """ 半径を求める """
    dist = 0
    for X,Y in XY:
        tmp = pow(X-x, 2) + pow(Y-y, 2)
        dist = max(dist, tmp)
    return sqrt(dist)

def midpoint(a,b):
    """ 2点の中点 """
    xa, ya = XY[a]
    xb, yb = XY[b]
    
    x = (xa + xb) / 2
    y = (ya + yb) / 2

    return (x, y)

def main():
    ans = float("inf")

    # 2点を直径とする円
    for a in range(N):
        for b in range(a+1,N):
            x,y = midpoint(a,b)
            r = radius(x,y)
            ans = min(ans, r)

    # 3点を通る円
    for a in range(N):
        for b in range(a+1,N):
            for c in range(b+1,N):
                x,y = circumcenter(a,b,c)
                r = radius(x,y)
                ans = min(ans, r)

    print("{0:.7f}".format(ans))

if __name__ == "__main__":
    main()