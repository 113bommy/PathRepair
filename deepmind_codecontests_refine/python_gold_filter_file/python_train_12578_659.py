a, b = map(int, input().split())
print(max(max(a + b, a - b), a * b))