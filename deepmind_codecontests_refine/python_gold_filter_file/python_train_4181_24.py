for x in range(int(input())):
    s=input()
    s=list(s)
    s.sort()
    l=len(s)
    t=len(set(s))
    if t!=l:
        print("NO")
    else:
        a = s[0]
        b = s[-1]
        if (ord(b) - ord(a) - l + 1) == 0:
            print("YES")
        else:
            print("NO")