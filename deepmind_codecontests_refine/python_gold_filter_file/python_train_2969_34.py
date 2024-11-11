n = input().split(' ')
day = int(n[0])
ident = n[2]

if ident == "week":
    if day < 5 or day == 7:
        print(52)
    elif day == 5 or day == 6:
        print(53)
else:
    if day <30:
        print(12)
    elif day == 30:
        print(11)
    else:
        print(7)