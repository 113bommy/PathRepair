import math

def f(t):
    return math.sqrt(abs(t)) + 5 * t ** 3

a = [int(input()) for _ in range(11)]
for i, t in reversed(list(enumerate(a))):
    y = f(t)
    if y > 400:
        print('f(', t, ') = MAGNA NIMIS!', sep='')
    else:
        print('f(', t, ') = %.2f' % y, sep='') 