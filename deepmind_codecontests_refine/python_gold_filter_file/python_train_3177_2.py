a, b, c = map(int, input().split())
x, y, z = map(int, input().split())
d_a = a - x
d_b = b - y
d_c = c - z
neg, pos = 0, 0
if d_a > 0:
    pos += d_a // 2
if d_b > 0:
    pos += d_b // 2
if d_c > 0:
    pos += d_c // 2
if d_a < 0:
    neg += d_a
if d_b < 0:
    neg += d_b
if d_c < 0:
    neg += d_c
if pos + neg >= 0:
    print("Yes")
else:
    print("No")