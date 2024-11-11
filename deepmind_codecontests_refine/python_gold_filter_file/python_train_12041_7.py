n = int(input())

if n < 6:
    print(-1)
else:
    for e in ((1, 2), (2, 3), (2, 4), (3, 5), (3, 6)):
        print(*e)
    for e in ((2, i) for i in range(7, n + 1)):
        print(*e)

for e in ((i, i + 1) for i in range(1, n)):
    print(*e)
