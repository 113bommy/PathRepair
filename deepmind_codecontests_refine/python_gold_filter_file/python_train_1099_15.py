n = int(input())
if n == 0:
    print(1)
else:
    n = n * 3
    n = n % 4
    if n == 0:
        print(6)
    else:
        print(2 ** n)
