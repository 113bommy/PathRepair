t, a, b = map(int, input().split())
num = 0

if t == 1:
    if a == 1:
        if b == 1:
            print("inf")
        else:
            print(0)
    else:
        i = 1
        while a**i < b:
            i += 1

        if a**i == b:
            num += 1

        dec = []
        m = b
        while m > 0:
            dec.append(m % a)
            m //= a

        sum = 0

        for i in range(0, len(dec)):
            sum += dec[i]

        if sum == a:
            num += 1

        print(num)
else:
    if a == b:
        num += 1
    if a != 1:
        dec = []
        m = b
        while m > 0:
            dec.append(m % a)
            m //= a

        sum = 0

        for i in range(0, len(dec)):
            sum += dec[i]*(t**i)

        if sum == a:
            num += 1

    print(num)

