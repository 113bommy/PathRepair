s = [int(input()) for i in range(11)]
s.reverse()
for x in s:
    r = abs(x) ** 0.5 + 5 * x ** 3
    if r > 400:
        print('f(%d) = %s' % (x, "MAGNA NIMIS!"))
    else:
        print('f(%d) = %.2f' % (x, r))