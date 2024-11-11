n, m = list(map(int, input().split()))

for i in range(n):
    if i % 2 == 0:
        for i in range(m):
            print('#', end='')
        print('')
    else:
        if not ((i + 1)//2) % 2 == 0:
            for i in range(m - 1):
                print('.', end='')
            print('#')
        else:
            print('#', end='')
            for i in range(m - 1):
                print('.', end='')
            print('')