a = [int(input()) for _ in range(11)][::-1]

for i in range(11):
    x = abs(a[i])**.5
    y = (a[i] ** 3) * 5
    r = x+y
    if r < 400:
        print(f"f({a[i]}) = {r:.2f}")
    else:
        print(f"f({a[i]}) = MAGNA NIMIS!")
