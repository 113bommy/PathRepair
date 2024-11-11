def gcd(a, b):
    if a == b: return a
    elif a > b:
        a, b = b, a
    while a > 0:
        a, b = b%a, a
    return b
 
for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    if n == 2:
        if x[0] == x[1]: print(0)
        else: print(max(x))
    elif n == 3:
        g = gcd(x[0], x[2])
        if x[1] % g > 0: print(g)
        elif x[0] % x[1] > 0 and x[2] % x[1] > 0: print(x[1])
        else: print(0)
    else:
        # n >= 4
        g1 = gcd(x[0], x[2])
        g2 = gcd(x[1], x[3])
        m1 = max(x[0], x[2])
        m2 = max(x[1], x[3])
        for i in range(4, n):
            if i % 2 == 0:
                if g1 > 1: g1 = gcd(g1, x[i])
                m1 = max(m1, x[i])
            if i % 2 == 1:
                if g2 > 1: g2 = gcd(g2, x[i])
                m2 = max(m2, x[i])
        if g1 == 1 and g2 == 1:
            print(0)
        elif g1 == 1 and g2 > 1:
            if m1 < g2: ans = g2
            elif m1 == g2: ans = 0
            elif m1 > g2:
                ans = g2
                for i in range(0, n, 2):
                    if x[i] % g2 == 0:
                        ans = 0
                        break
            print(ans)
        elif g1 > 1 and g2 == 1:
            if m2 < g1: ans = g1
            elif m2 == g1: ans = 0
            elif m2 > g1:
                ans = g1
                for i in range(1, n, 2):
                    if x[i] % g1 == 0:
                        ans = 0
                        break
            print(ans)
        elif g1 > 1 and g2 > 1:
            if m1 < g2: ans = g2
            elif m2 < g1: ans = g1
            elif m1 == g2: ans = 0
            elif m2 == g1: ans = 0
            #elif gcd(g1, g2) > 1: ans = 0
            else:
                # gcd(g1, g2) = 1
                # m1 > g2 and m2 > g1
                ans = g1
                for i in range(1, n, 2):
                    if x[i] % g1 == 0:
                        ans = 0
                        break
                if ans == 0:
                    ans = g2
                    for i in range(0, n, 2):
                        if x[i] % g2 == 0:
                            ans = 0
                            break
            print(ans)