# A. Выгодный проезд
n, m, a, b = map(int, input().split())
abon = n // m * b + n % m * a
proezd = n * a
abon2 = (n // m +1) * b

if proezd <= abon and proezd <= abon2:
    print(proezd)
elif abon <= proezd and abon <= abon2:
    print(abon)
elif abon2 <= proezd and abon2 <= abon:
    print(abon2)
