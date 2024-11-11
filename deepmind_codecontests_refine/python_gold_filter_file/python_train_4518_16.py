# A * X ^ n = B

A, B, n = map(int, input().split())

for X in range(-1000, 1002):
    if (A * pow(X, n) == B):
        break

print('No solution' if X > 1000 else X)