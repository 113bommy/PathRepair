data = [int(input()) for x in range(11)]

for x in data[::-1]:
    res = x ** 3 * 5 + (abs(x) ** 0.5)
    if res >= 400:
        print(f'f({x}) = MAGNA NIMIS!')
    else:
        print(f'f({x}) = {res:0.2f}')
