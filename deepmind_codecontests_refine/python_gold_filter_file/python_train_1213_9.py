rd = lambda: map(int, input().split())
n, a, b = rd()
l, *m = list(rd())
m.sort()
x = l * a / b - l
for y in m:
    x -= y
    if x < 0:
        break
    n -= 1
print(n - 1)
