x, A, B = map(int, input().split())
print("A" if abs(A-x) < abs(B-x) else "B")