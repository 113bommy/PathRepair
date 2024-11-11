A, B = map(int, input().split())
print(A + B if not B % A else B - A)