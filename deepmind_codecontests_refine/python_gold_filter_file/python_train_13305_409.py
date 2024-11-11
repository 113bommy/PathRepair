a, b = [int(_) for _ in input().split()]
print(a + b if b % a == 0 else b - a)
