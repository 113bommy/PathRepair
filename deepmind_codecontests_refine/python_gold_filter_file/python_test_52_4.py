t = int(input())
for i in range(t):
    n, k = tuple(map(int, input().split()))
    i, r = 0, 0
    while k != 0:
        if k % 2:
            r += n**i
        i += 1
        k //= 2
    print(r % (10**9 + 7), '\n')
