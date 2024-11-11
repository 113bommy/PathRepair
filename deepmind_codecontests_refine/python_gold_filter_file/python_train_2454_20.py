a, b, c = [int(input()) for _ in' '*3]
s = -7
while a >= 0 and b >= 0 and c >= 0: a, b, c, s = a - 1, b - 2, c - 4, s + 7
print(s)