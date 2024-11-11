a, b, c = map(float, input().split())
D = b ** 2 - (4 * a * c)
if D < 0:
    print(0)
elif a == 0 and b == 0 and c != 0:
    print(0)
elif a == 0 and b == 0 and c == 0:
    print(-1)
elif a == 0:
    x0 = c / -(b)
    print(1)
    print(x0)
elif b == 0:
    print(1)
    print(0)
elif D == 0 and (a > 0 or a < 0):
    x = -(b) / (2 * a)
    print(1)
    print(x)
elif D > 0 and (a > 0 or a < 0):
    x1 = (-(b) + D ** 0.5) / (2 * a)
    x2 = (-(b) - D ** 0.5) / (2 * a)
    print(2)
    g = [x1, x2]
    for i in sorted(g):
        print(i)
