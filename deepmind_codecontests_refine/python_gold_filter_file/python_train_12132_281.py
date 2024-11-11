a = str(bin(int(input())))
a = a[:2] + (8 - len(a)) * '0' + a[2:]
print(int(a[-5]) * 1 + int(a[-2]) * 2 + int(a[-4]) * 4 + int(a[-3]) * 8 + int(a[-1]) * 16 + int(a[-6]) * 32)
