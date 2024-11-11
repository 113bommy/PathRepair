n = int(input())

if n % 2 == 1:
    remaindr = n // 2
    print(remaindr)
    print('2 '*(remaindr-1)+'3')
else:
    remaindr = n // 2
    print(remaindr)
    print('2 '*remaindr)
