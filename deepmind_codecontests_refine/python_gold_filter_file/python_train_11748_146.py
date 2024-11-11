X, A, B = [int(i) for i in input().split()]
print("delicious" if B <= A else "safe" if (B-A) <= X else "dangerous")