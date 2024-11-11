t = int(input())

for test in range(t):
    n, k = map(int, input().split())
    x = [False for i in range(n)]

    for xi in map(int, input().split()):
        x[xi-1] = True
        n = n - 1

    time = 1
    while n > 0:

        x2 = x.copy()
        for i in range(len(x)):
            if x[i] is True:
                if i > 0 and x2[i-1] is False:
                    x2[i-1] = True
                    n = n - 1
                if i + 1 < len(x) and x2[i+1] is False:
                    x2[i+1] = True
                    n = n - 1
        x = x2.copy()
        time = time + 1

    print(time)

