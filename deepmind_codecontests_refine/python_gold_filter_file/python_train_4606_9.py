a = bin(int(input())).replace("0b", "")
a = list(a)
a.__reversed__()
while len(a) < 6:
    a.insert(0, '0')
a = "".join(a)
n = a[0] + a[5] + a[3] + a[2] + a[4] + a[1]
print(int("".join(n), 2))
