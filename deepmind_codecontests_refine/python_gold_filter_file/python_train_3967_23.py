n, m = map(int, input().split())
a = []
b = []
check = True
while n >= 0:
    if check == True:
        a.append(5)
        n -= 5
        b.append(4)
        check = False
    else:
         check = True
         a.append(4)
         n -= 4
         b.append(5)


if m != 1:
    a.append(5)
    b.append(6)
else:
    a.append(5)
    b.append(5)

print(*a, sep = "")
print(*b, sep = "")
