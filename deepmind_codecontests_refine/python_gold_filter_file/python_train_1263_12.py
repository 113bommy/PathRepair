b, k = (int(i) for i in input().strip().split())
a = [int(x) for x in input().split()]
if b % 2 == 0 and a[k - 1] % 2 > 0:
    print('odd')
elif b % 2 == 0 and a[k - 1] % 2 == 0:
    print('even')
else:
    c = 0
    i = k
    while i > 0:
        if a[i - 1] % 2 == 0:
            c += 1
        i -= 1
    if (k - c) % 2 == 0:
        print('even')
    else:
        print('odd')
