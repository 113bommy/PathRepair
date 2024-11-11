k = int(input())

if k % 2 == 0:
    print(k//2)
    print(k//2 * '2 ')
else:
    print(k//2)
    print((k//2-1) * '2 ', end='')
    print(3)