a = int(input())
b = int(input())
c = int(input())
o = 0
while a >= 0 and b >= 0 and c >= 0:
    a -= 1
    b -= 2
    c -= 4
    o += 7
print(o - 7)
