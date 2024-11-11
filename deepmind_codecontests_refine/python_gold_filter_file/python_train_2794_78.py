X, A, B = [int(s) for s in input().split()]
print('A' if abs(X - A) < abs(X - B) else 'B')