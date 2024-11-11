def check(s, m, parity):
    lo = parity
    hi = m - (m - parity) % 2

    for c in s:
        if c == '0':
            lo += 1
            hi += 1
        elif c == '1':
            lo -= 1
            hi -= 1
        else:
            lo -= 1
            hi += 1

        if lo < 0:
            lo += 2
        if hi > m:
            hi -= 2

        if lo > hi:
            return False

    return True


s = input()
l, r = 0, len(s)
while l + 1 < r:
    m = (l + r) // 2
    if check(s, m, 0) or check(s, m, 1):
        r = m
    else:
        l = m
print(r)
