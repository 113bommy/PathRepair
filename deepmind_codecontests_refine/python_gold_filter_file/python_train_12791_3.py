for _ in range(int(input())):
    xa, ya, ra, xb, yb, rb = list(map(float,input().split()))
    dAB = ((xa - xb) ** 2 + (ya - yb) ** 2) ** 0.5
    if ra + rb < dAB:
        print('0')
    elif dAB + rb < ra:
        print('2')
    elif dAB + ra < rb:
        print('-2')
    else:
        print('1')