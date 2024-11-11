a = [int(i) for i in input().split()]
r = a[0]
c = a[1]
if r == 1 and c == 1:
    print(0)
elif c != 1:
    for i in range(1, r + 1):
        for j in range(1, c + 1):
            print(i * (j + r), end=' ')
        print()
else:
    for i in range(2, 2 + r):
        print(i)
