a, b, c, d = map(int, input().split())
while a > 0 and b > 0: c -= b; a -= d
print('Yes' if c <= 0 else 'No')