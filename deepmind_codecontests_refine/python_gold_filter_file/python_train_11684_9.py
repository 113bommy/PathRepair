t = int(input())

for _ in range(t):
    n, ok = int(input()), 0
    a = list(map(int, input().split()))
    for x in range(1, n):
        a[x] += a[x - 1]
    for x in range(n):
        if a[x] % 2 == 0:
            ok = 1
            print(x + 1)
            for y in range(1, x + 2):
                print(y, end=' ')
            print()
            break
    if ok:
        continue
    for x in range(0, n-1):
        if ok == 0:
            for y in range(x+1, n):
                if (a[y] - a[x]) % 2 == 0:
                    ok = 1
                    print(y - x)
                    for k in range(x + 1, y + 1):
                        print(k + 1, end=' ')
                    print()
                    break
    if ok == 0:
        print("-1")