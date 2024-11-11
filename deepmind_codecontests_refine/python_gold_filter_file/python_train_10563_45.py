n, m = [*map(int, input().split())]
a = {}
for i in range(m):
    x, y = input().split()
    a[x] = y
    a[y] = x
for i in list(input().split()):
    print(i if len(i) <= len(a[i]) else a[i], end = " ")
print()

