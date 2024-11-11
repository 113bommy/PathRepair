st = input()
if st[-4:] == "week":
    if st[0] in "56": r = 53
    else: r = 52
else:
    if int(st[:2]) <= 29: r = 12
    elif st[:2] == "31": r = 7
    else: r = 11
print(r)
