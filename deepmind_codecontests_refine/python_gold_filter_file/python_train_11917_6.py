n = int(input())
i = 0
h = 0
while n >= 0:
    h += 1
    i += h
    n -= i
print(h - 1)