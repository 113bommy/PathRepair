import string

n, k = map(int, input().split())

print(string.ascii_lowercase[:k] * (n // k) + string.ascii_lowercase[:n % k])

