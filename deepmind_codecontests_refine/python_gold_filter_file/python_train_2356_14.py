input()
a = b = s = 0
for c in map(int, input().split()):
    if a and (a > b < c or a < b > c): s += 1
    a, b = b, c
print(s)