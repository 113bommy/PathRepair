def s(a, b):
    r = []
    while b > 0:
        r += [b % a]
        b //= a
    if len(r) == len(set(r)):
        print('YES')
    else:
        print('NO')
a, b = map(int, input().split())
s(b, a)