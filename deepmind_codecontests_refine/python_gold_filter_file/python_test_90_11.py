t = int(input())

for w in range(t):
    x, y = map(int, input().split())

    if x > y:
        print(x + y)
    elif y % x == 0:
        print(x)
    else:
        k = y % x
        k //= 2
        print(y - k)