n, a, b = map(int, input().split())
min_a_b = a * (n-1) + b
max_a_b = a + b * (n-1)
print(max(0, max_a_b - min_a_b + 1))