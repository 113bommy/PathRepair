a, x, y = map(int, input().split())
multiple = y // a

if abs(x) >= a or y == y // a * a or y < 0:
    print(-1)
elif x == 0 and multiple % 2 == 0 and multiple != 0:
    print(-1)
elif abs(x) >= (a + 1) // 2 and (multiple % 2 == 1 or multiple == 0):
    print(-1)
elif multiple == 0:
    print(1)
elif (multiple - 1) % 2 == 0:
    print((multiple - 1) // 2 * 3 + 2)
elif x < 0:
    print((multiple - 1) // 2 * 3 + 3)
else:
    print((multiple - 1) // 2 * 3 + 4)
