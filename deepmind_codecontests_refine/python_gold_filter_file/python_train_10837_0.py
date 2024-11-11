s = input()
l = len(s)
if l <= 20:
    print(1, l)
    print(s)
elif l <= 40:
    print(2, (l + 1) // 2)
    print(s[:(l + 1) // 2])
    print(s[(l + 1) // 2:], end='')
    if l % 2:
        print('*')
elif l <= 60:
    print(3, (l + 2) // 3)
    if l % 3 == 0:
        print(s[:l // 3])
        print(s[l // 3: l // 3 * 2])
        print(s[l // 3 * 2:])
    elif l % 3 == 1:
        l += 2
        print(s[:l // 3])
        print(s[l // 3:l // 3 * 2 - 1], '*', sep='')
        print(s[l // 3 * 2 - 1:], '*', sep='')
    elif l % 3 == 2:
        l += 1
        print(s[:l // 3])
        print(s[l // 3:l // 3 * 2])
        print(s[l // 3 * 2:], '*', sep='')
elif l <= 80:
    print(4, (l + 3) // 4)
    if l % 4 == 1:
        l += 3
        print(s[:l // 4])
        print(s[l // 4:l // 4 * 2 - 1], '*', sep='')
        print(s[l // 4 * 2 - 1:l // 4 * 3 - 2], '*', sep='')
        print(s[l // 4 * 3 - 2:], '*', sep='')
    elif l % 4 == 2:
        l += 2
        print(s[:l // 4])
        print(s[l // 4:l // 4 * 2])
        print(s[l // 4 * 2:l // 4 * 3 - 1], '*', sep='')
        print(s[l // 4 * 3 - 1:], '*', sep='')
    elif l % 4 == 3:
        l += 1
        print(s[:l // 4])
        print(s[l // 4:l // 4 * 2])
        print(s[l // 4 * 2:l // 4 * 3])
        print(s[l // 4 * 3:], '*', sep='')
    elif l % 4 == 0:
        print(s[:l // 4])
        print(s[l // 4:l // 4 * 2])
        print(s[l // 4 * 2:l // 4 * 3])
        print(s[l // 4 * 3:])
else:
    print(5, (l + 4) // 5)
    if l % 5 == 1:
        l += 4
        print(s[:l // 5])
        print(s[l // 5:l // 5 * 2 - 1], '*', sep='')
        print(s[l // 5 * 2 - 1:l // 5 * 3 - 2], '*', sep='')
        print(s[l // 5 * 3 - 2:l // 5 * 4 - 3], '*', sep='')
        print(s[l // 5 * 4 - 3:], '*', sep='')
    elif l % 5 == 2:
        l += 3
        print(s[:l // 5])
        print(s[l // 5:l // 5 * 2])
        print(s[l // 5 * 2:l // 5 * 3 - 1], '*', sep='')
        print(s[l // 5 * 3 - 1:l // 5 * 4 - 2], '*', sep='')
        print(s[l // 5 * 4 - 2:], '*', sep='')
    elif l % 5 == 3:
        l += 2
        print(s[:l // 5])
        print(s[l // 5:l // 5 * 2])
        print(s[l // 5 * 2:l // 5 * 3])
        print(s[l // 5 * 3:l // 5 * 4 - 1], '*', sep='')
        print(s[l // 5 * 4 - 1:], '*', sep='')
    elif l % 5 == 4:
        l += 1
        print(s[:l // 5])
        print(s[l // 5:l // 5 * 2])
        print(s[l // 5 * 2:l // 5 * 3])
        print(s[l // 5 * 3:l // 5 * 4])
        print(s[l // 5 * 4:], '*', sep='')
    elif l % 5 == 0:
        print(s[:l // 5])
        print(s[l // 5:l // 5 * 2])
        print(s[l // 5 * 2:l // 5 * 3])
        print(s[l // 5 * 3:l // 5 * 4])
        print(s[l // 5 * 4:])
