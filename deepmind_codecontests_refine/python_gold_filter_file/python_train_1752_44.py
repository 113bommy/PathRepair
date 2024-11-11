a, b, c, k = map(int, input().split())
print(a - b if k % 2 == 0 else b - a)