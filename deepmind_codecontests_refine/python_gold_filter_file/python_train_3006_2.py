def circum(x1,y1,x2,y2,x3,y3):
    a1 = 2 * (x2 - x1)
    b1 = 2 * (y2 - y1)
    c1 = x1 ** 2 - x2 ** 2 + y1 ** 2 - y2 ** 2
    a2 = 2 * (x3 - x1)
    b2 = 2 * (y3 - y1)
    c2 = x1 ** 2 - x3 ** 2 + y1 ** 2 - y3 ** 2
    X = (b1 * c2 - b2 * c1)/(a1 * b2 - a2 * b1)
    Y = (c1 * a2 - c2 * a1)/(a1 * b2 - a2 * b1)
    R = ((x1 - X) ** 2 + (y1 - Y) ** 2) ** 0.5
    return map(lambda n: round(n,3), [X,Y,R])
N = int(input())
ans = []
for i in range(N):
    ans.append(circum(*list(map(float,input().split()))))
for i in range(N):
    print('{0:.3f} {1:.3f} {2:.3f}'.format(*ans[i]))