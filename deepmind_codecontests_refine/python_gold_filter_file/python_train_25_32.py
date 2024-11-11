for _ in range(int(input())):
    n = int(input())
    ml = []
    kl = []
    for i in range(n):
        ml.append(input())
    x = [ml[0][1], ml[1][0], ml[n-1][n-2], ml[n-2][n-1]]
    x = [int(i) for i in x]
    if x in [[0, 0, 0, 0], [1, 1, 1, 1]]:
        print(2)
        print(n, n-1)
        print(n-1, n)
    elif x in [[1, 1, 0, 0], [0, 0, 1, 1]]:
        print(0)
    elif x in [[0, 0, 0, 1], [1, 1, 1, 0]]:
        print(1)
        print(n, n-1)
    elif x in [[0, 0, 1, 0], [1, 1, 0, 1]]:
        print(1)
        print(n-1, n)
    elif x in [[0, 1, 0, 0], [1, 0, 1, 1]]:
        print(1)
        print(1, 2)
    elif x in [[1, 0, 0, 0], [0, 1, 1, 1]]:
        print(1)
        print(2, 1)
    elif x in [[0, 1, 0, 1], [1, 0, 1, 0]]:
        print(2)
        print(2, 1)
        print(n, n-1)
    elif x in [[0, 1, 1, 0], [1, 0, 0, 1]]:
        print(2)
        print(2, 1)
        print(n-1, n)
    