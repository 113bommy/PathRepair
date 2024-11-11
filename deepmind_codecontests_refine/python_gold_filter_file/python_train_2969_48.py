l = [*map(str,input().split())]
if l[2][0]=='w':
    print(53 if int(l[0]) in [6,5] else 52)
else:
    a=int(l[0])
    if a in [30]:
        print(11)
    elif a==31:
        print(7)
    else:
        print(12)
    