t = int(input())
for _ in range(t):
    x, y, a, b = map(int, input().split())
    t = (y - x) / (a + b)
    if t == int(t) and t > 0:
        print(int(t))
    else:
        print(-1)
