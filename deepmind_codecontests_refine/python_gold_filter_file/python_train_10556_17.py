a, b = map(int, input().strip().split())
if a > 0 and b > 0:
    print(0, a + b, b + a, 0)
elif a < 0 and b > 0:
    print(-(-a + b), 0, 0, -a + b)
elif a > 0 and b < 0:
    print(0, -(a - b), a - b, 0)
else:
    print(a + b, 0, 0, a + b)
