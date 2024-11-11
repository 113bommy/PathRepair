X, A, B = map(int, input().split())
print("delicious" if A >= B else "safe" if B - A <= X else "dangerous")
