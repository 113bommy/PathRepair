n, m = map(int, input().split())
print(max(1, m - 1 if m - 1 >= n - m else m + 1))