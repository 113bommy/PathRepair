n = int(input())
k = n // 2
if n % 2 == 0:
    print(n * k)
    for x in range(k):
        print('C.' * k)
        print('.C' * k)
else:
    print((n + 1) * k + 1)
    for x in range(k):
        print('C.' * k + 'C')
        print('.C' * k + '.')
    print('C.' * k + 'C')