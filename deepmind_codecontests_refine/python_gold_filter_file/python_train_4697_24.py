a, b, c = map(int, input().split())

print(max(0, max(a, b, c) - (a + b + c - max(a, b, c)) + 1))