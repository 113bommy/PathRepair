a, b, c, d = map(int, input().split())

res1 = max((3 * a / 10), a - a/250 * c)
res2 = max((3 * b / 10), b - b/250 * d)


if res1 > res2:
    print("Misha")
elif res2 > res1:
    print("Vasya")
else:
    print("Tie")