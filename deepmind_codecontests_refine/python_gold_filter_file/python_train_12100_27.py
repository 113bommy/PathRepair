n = int(input())
for i in range(n):
    x, y, a, b = map(int, input().split())
    if (y - x) % (a + b) == 0:
        print((y - x) // (a + b))
    else:
        print(-1)