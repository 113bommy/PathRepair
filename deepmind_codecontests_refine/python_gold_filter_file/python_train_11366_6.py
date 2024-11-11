a, b, n = map(int, input().split())
i = 1
q = n
q1 = n

while q > 0:
    if i % 2 == 1:
        ac = a
        q1 = q
        while q1 > 0:
            ac, q1 = q1, ac % q1
        q = q - ac
        if q >= 0:
            i += 1
        else:
            i -= 1
    else:
        bc = b
        q1 = q
        while q1 > 0:
            bc, q1 = q1, bc % q1
        q = q - bc
        if q >= 0:
            i += 1
        else:
            i -= 1

if i % 2 == 0:
    print(0)
else:
    print(1)
