from math import ceil
n = int(input())
print(ceil(n ** 2 / 2))
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i % 2 == j % 2:
            print('C', end='')
        else:
            print('.', end='')
    print()
