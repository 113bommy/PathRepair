n = int(input())
s = 0
if n >= 100:
    s += n // 100
    n %= 100
if n >= 20:
    s += n // 20
    n %= 20
if n >= 10:
    s += n // 10
    n %= 10
if n >= 5:
    s += n // 5
    n %= 5
if n >= 1:
    s += n // 1
    n %= 1
print(s)
