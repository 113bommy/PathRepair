s = input()
x = int(s[0:2])
if 'week' in s:
    if 5 <= x <= 6:
        print(53)
    else:
        print(52)


else:
    if x == 30:
        print(11)
    elif x == 31:
        print(7)
    else:
        print(12)