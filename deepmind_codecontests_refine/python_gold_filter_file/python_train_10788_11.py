import sys
n = int(input())
l = sum((1 for i in range(n) if int(input().split()[0]) > 0))
print("Yes" if n - l <= 1 or n - l >= n - 1 else "No")

