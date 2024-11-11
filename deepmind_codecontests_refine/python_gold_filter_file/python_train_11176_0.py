def plane(a, b, c):
    if a == b == 0 != c:
        return 0
    else:
        return -1

def hline(b1, c1, a2, b2, c2):
    if b1 == 0:
        if c1 == 0:
            return plane(a2, b2, c2)
        else:
            return -1
    elif a2 == 0:
        if b2 == 0 != c2:
            return 0
        elif c2 * b1 == c1 * b2:
            return -1
        else:
            return 0
    else:
        return 1

def vline(a1, c1, a2, b2, c2):
    return hline(a1, c1, b2, a2, c2)


def intersect(a1, b1, c1, a2, b2, c2):
    if a1 == b1 == 0:
        if c1 == 0:
            return plane(a2, b2, c2)
        else:
            return 0
    if a1 == 0:
        return hline(b1, c1, a2, b2, c2)
    if b1 == 0:
        return vline(a1, c1, a2, b2, c2)
    if a2 == b2 == 0:
        if c2 == 0:
            return plane(a1, b1, c1)
        else:
            return 0
    if a2 == 0:
        return hline(b2, c2, a1, b1, c1)
    if b2 == 0:
        return vline(a2, c2, a1, b1, c1)
    else:
        if a1 * b2 == a2 * b1:
            if c1 * a2 == c2 * a1:
                return -1
            else:
                return 0
        else:
            return 1




a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

print(intersect(a1, b1, c1, a2, b2, c2))

