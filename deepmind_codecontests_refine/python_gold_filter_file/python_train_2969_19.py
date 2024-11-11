a=input()
if len(a)==11:
            s=""
            s+=a[0]
            s+=a[1]
            s=int(s)
            if s==30:
                print(11)
            elif s==31:
                print(7)
            else:
                print(12)
elif len(a)==9:
    s=""
    s=a[0]
    s=int(s)
    if s==6 or s==5:
        print(53)
    else:
        print(52)
else:
    print(12)
