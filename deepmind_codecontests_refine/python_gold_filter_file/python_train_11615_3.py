n = int(input())
time = input()
numbers = time.split(":")
h, m = numbers[0], numbers[1]
a, b = int(h), int(m)
if n == 12:
    if a > 12:
        if a % 10 == 0:
            h = "1" + h[1]
        else:
            h = "0" + h[1]
    elif a == 0:
        h = "10"
else:
    if a >= 24:
        h = "0" + h[1]
if b >= 60:
    m = "0" + m[1]
print("%s:%s" % (h, m))