X, A, B = [int(_) for _ in input().split()]
print("delicious" if B <= A else "safe" if B - A <= X else "dangerous")