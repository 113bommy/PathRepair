from fractions import Fraction
t = int(input())
for _ in range(t):
    a, b = map(lambda x: Fraction(x), input().split(' '))
    if b == 0:
        print(1)
        continue
    elif a == 0:
        print(0.5)
        continue

    up = a * (b + b + a / 4) / 2 - max(0, a - 4 * b) * (a / 4 - b) / 2
    down = a * 2 * b
    print(float(up/down))
