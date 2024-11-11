s = input()
s = s.split("=")
a = s[0]
b = s[1]
na = a.count("|")
nb = b.count("|")
if abs(na-nb)!=2 and abs(na-nb)!=0:
    print("Impossible")
else:
    t = na-nb
    if t>0:
        q = a.split("+")
        n1 = q[0].count("|")
        n2 = q[1].count("|")
        if n1>1:
            print("".join(a[1:]), end="=")
        else:
            print("".join(a[:-1]), end="=")
        print("|", end="")
        print("".join(b))
    elif t<0:
        print("".join(a), end="")
        print("|", end="=")
        print("".join(b[1:]))
    else:
        print("=".join(s))