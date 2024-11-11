def c(r1, c1, r2, c2):
    for x in range(-10, 10):
        if r2 - x == r1 and c2 - x == c1:
            return True
        if r2 - x == r1 and c2 + x == c1:
            return True
        if r2 + x == r1 and c2 - x == c1:
            return True
        if r2 - x == r1 and c2 - x == c1:
            return True
    return False
def main(r1, c1, r2, c2):
    r = min(1, abs(r2 - r1)) + min(1, abs(c2 - c1))
    b = 2
    if (r1 + c1) % 2 != (r2 + c2) % 2:
        b = 0
    if c(r1, c1, r2, c2):
        b = 1

    k = max(abs(r2 - r1), abs(c2 - c1))

    return '{} {} {}'.format(r, b, k)

print(main(*list(map(int, input().split(' ')))))
