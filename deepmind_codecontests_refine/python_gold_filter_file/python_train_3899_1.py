from collections import defaultdict

def main():
    MAX = 3002
    (n, v) = map(int, input().split(' '))
    m = defaultdict(list)
    for i in range(n):
        (ai, bi) = map(int, input().split(' '))
        m[ai].append(bi)
    
    a = [[] for i in range(MAX)]
    for i in range(0, MAX):
        if i in m:
            a[i] = m[i]
        else:
            a[i] = [0]
    r = 0
    l = 0
    for i in range(1, MAX):
        xs = []
        vv = v
        for ai in a[i]:
            y = 0
            if l > 0 and vv > 0:
                y = min(vv, l)
                r += y
                vv -= y
                l -= y
            x = min(vv, ai)
            vv -= x
            r += x
            if ai - x > 0:
                xs.append(ai - x)
            #print(i, x, y, r, xs)
        l = 0
        for x in xs:
            if x > 0:
                l += x
    return r
print(main())
