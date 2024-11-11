
a = int(input())
b = int(input())
n = int(input())
m = max(0, n - b)

M = min(a, n)
print(M - m + 1)
