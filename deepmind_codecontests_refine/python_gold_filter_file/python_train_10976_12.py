n, k = map(int, input().split())
y = map(int, input().split())
remainder = [5 - yi for yi in y]
possible = sum([ri >= k for ri in remainder]) // 3
print(possible)
