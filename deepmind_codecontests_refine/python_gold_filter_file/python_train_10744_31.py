for t in range(int(input())):
    c = sorted([*map(int, input().split())])
    print('Yes' if ((c[2] - 1) <= c[0] + c[1]) else 'No')
