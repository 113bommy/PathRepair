n = int(input())
a = list(map(int, input().split()))
a.sort()
if n % 2:
    for i in range(0, n, 2):
        print(a[i], end=' ')
    for i in range(n - 2, -1, -2):
        print(a[i], end=' ')
else:
    for i in range(0, n, 2):
        print(a[i], end=' ')
    for i in range(n - 1, -1, -2):
        print(a[i], end=' ')