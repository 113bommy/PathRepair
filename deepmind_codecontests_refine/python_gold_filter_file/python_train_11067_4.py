k, s = map(int, input().split())
x, y = map(int, input().split())
if x > y: x, y = y, x
for i in range(k - 1):
    a, b = map(int, input().split())
    if a > b:
        if b > x: x = b
        if a < y: y = a
    else:
        if a > x: x = a
        if b < y: y = b
if x > y: print(-1)
elif s < x: print(x - s)
elif s > y: print(s - y)
else: print(0)