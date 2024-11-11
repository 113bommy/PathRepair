n, x, y = map(int, input().split())
a = list(map(int, input().split()))

if n == 1:
    print(abs(a[-1] - y))
else:
    print(max(abs(a[-1] - y), abs(a[-1] - a[-2])))
