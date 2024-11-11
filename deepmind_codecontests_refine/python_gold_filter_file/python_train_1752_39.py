a, b, c, k = list(map(int, input().split()))
print(a - b if k % 2 == 0 else b - a)