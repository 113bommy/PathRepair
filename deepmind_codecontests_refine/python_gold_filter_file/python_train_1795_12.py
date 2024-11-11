 
def f(x):
    a = abs(x) ** 0.5
    b = (x ** 3) * 5
    r = a + b
    return 'MAGNA NIMIS!' if 400 < r else format(r, '.2f')
 
for x in reversed(list(int(input()) for _ in range(11))):
    print('f({}) = {}'.format(x, f(x)))