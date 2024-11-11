if __name__ == '__main__':
    n = int(input())
    larr = list(map(int, input().split()))
    rarr = list(map(int, input().split()))

    rez = [-1 for _ in range(n)]

    x = n
    mx = list(filter(lambda i: larr[i] == rarr[i] == 0 and rez[i] == -1, range(n)))

    while mx:
        for i in mx:
            rez[i] = x

        rd = 0
        for i in range(n):
            if rez[i] == x:
                rd += 1
            elif rez[i] == -1:
                larr[i] -= rd

        ld = 0
        for i in reversed(range(n)):
            if rez[i] == x:
                ld += 1
            elif rez[i] == -1:
                rarr[i] -= ld

        x -= 1
        mx = list(filter(lambda i: larr[i] == rarr[i] == 0 and rez[i] == -1, range(n)))

    if any(map(lambda o: o == -1, rez)):
        print('NO')
    else:
        print('YES')
        print(*rez)
