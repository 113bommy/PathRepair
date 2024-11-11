W, a, b = map(int, input().split())

print(max(0, abs(b - a) - W))