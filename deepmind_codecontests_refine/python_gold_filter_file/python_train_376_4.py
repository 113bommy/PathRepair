a = int(input())
b = int(input())

if a > b:
    a, b = b, a

if b - a == 1:
    print(1)
else:
    n = (b - a) // 2
    x = ((1 + n) * n) / 2

    x *= 2

    if (b - a) % 2 != 0:
        x += (n + 1)

    print(int(x))
