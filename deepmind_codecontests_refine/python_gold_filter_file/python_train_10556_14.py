x, y = map(int, input().split())
m = 1 if x*y < 0 else -1
c = y - m * x
print(-1 * c // m, 0, 0, c) if -1 * c // m < 0 else print(0, c, -1 * c // m, 0)
