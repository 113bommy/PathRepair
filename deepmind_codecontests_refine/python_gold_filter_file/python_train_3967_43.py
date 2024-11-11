n, m = map(int, input().split())
nc = n//8 + bool(n%8)
a = '8' * nc + '9'
b = '9' * len(a) + '1' * len(a)
print(a, b, sep = '\n')
