k, x = map(int, input().split())
A = list(range(x - k + 1, x + k))
print(*A)