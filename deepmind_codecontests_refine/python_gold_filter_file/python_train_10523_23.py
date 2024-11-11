while True:
    (m, f, r) = [int(i) for i in input().split()]
    if m == f == r == -1:
        break

    total = m + f
    if m == -1 or f == -1 or total < 30:
        print('F')
    elif total < 50 and r < 50:
        print('D')
    elif total < 65:
        print('C')
    elif total < 80:
        print('B')
    else:
        print('A')