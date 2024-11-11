s=input().split()
day=int(s[0])
if s[2]=='week':
    if day==5 or day==6:
        print(53)
    else:
        print(52)
else:
    if day==30:
        print(11)
    elif day==31:
        print(7)
    else:
        print(12)