x = int(input())
h, m = [int(x) for x in input().split()]
y = 0
while not('7' in (str(h) + str(m))):
    y += 1
    m -= x
    if m < 0:
        m += 60
        h -= 1
    if h < 0:
        h += 24
print(y)