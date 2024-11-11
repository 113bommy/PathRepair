N, A, B = map(int, input().split())
print("Alice" if abs(A - B) % 2 == 0 else "Borys")