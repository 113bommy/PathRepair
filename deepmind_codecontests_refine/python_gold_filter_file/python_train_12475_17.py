n, a, b = map(int, input().split())
print("Borys" if (b - a) % 2 == 1 else "Alice")