n = int(input())
print("Yes" if any((n - i*7) % 4 == 0 for i in range(n // 7 + 1)) else "No")