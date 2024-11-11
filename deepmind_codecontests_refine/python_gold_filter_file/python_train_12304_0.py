a, b = map(int, input().split())
if a == b:
    print(a * 10 + 1, a * 10 + 2)
elif b - a == 1:
    print(b * 10 - 1, b * 10)
elif b == 1 and a == 9:
    print(a, b * 10)
else:
    print(-1)