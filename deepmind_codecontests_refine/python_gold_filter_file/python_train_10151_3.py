import fractions

t, w, b = map(int, input().split())

lcm = w * b // fractions.gcd(w, b)
ex = (b > 1) and (w > 1)
tdl = (t // lcm)
fr = fractions.Fraction(min(w, b) * (tdl - 1) + (1 + min(t % lcm, w - 1, b - 1)) + min(w - 1, b - 1), t)

if str(fr) == '1':
    print('1/1')
elif str(fr) == '0':
    print('0/1', sep='')
else:
    print(fr)