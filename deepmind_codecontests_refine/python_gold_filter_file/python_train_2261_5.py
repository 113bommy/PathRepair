n, s = int(input()), 0
*a, = map(int, input().split())
for i in range(2 * n - 1, - 1, -2):
    s += i - a.index(a[i]) - 1
    a.remove(a[i])
print(s)