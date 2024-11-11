def bear(x, y):
    if x > 0 and y > 0:
        return 0, x + y, x + y, 0
    elif x < 0 < y:
        return -1 * (abs(x) + abs(y)), 0, 0, abs(x) + abs(y)
    elif x < 0 and y < 0:
        return -1 * (abs(x) + abs(y)), 0, 0, -1 * (abs(x) + abs(y))
    return 0, -1 * (abs(x) + abs(y)), abs(x) + abs(y), 0


X, Y = [int(i) for i in input().split()]
print(*bear(X, Y))
