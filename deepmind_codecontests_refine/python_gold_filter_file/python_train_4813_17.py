t = int(input())

for i in range(t):
    line = input()
    [a, b, c] = [int(x) for x in line.split(' ')]
    #print(a, b, c)

    mincost = 10000000000
    bestsol = [a, b, c]
    for ai in range(1, c * 2):
        ini = ai
        bi = ini
        while bi <= 20001:
            if bi % ai == 0 and abs(bi - b) + abs(ai - a) <= mincost:
                divis = c // bi
                for ci in [divis * bi, divis * bi + bi]:
                    if ci % bi == 0 and ci >= bi and c <= 20001:
                        cost = abs(ci - c) + abs(bi - b) + abs(ai - a)
                        if cost < mincost:
                            bestsol = [ai, bi, ci]
                            mincost = cost
            bi += ini

    
    print(mincost)
    print(' '.join([str(x) for x in bestsol]))
