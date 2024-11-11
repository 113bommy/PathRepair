
for _ in range(int(input())):
    n = input()
    s = input()
    s1=s[::-1]
    t, m,h = 0,0,0
    if s.count("T") == 2 * s.count("M"):

        f = 0
        for i in range(len(s)):
            if s[i] == "T":
                t += 1
            elif s[i] == "M":
                m += 1
            # print(t,m)
            if m > t:
                h = -1
                f=1
                break
        if f == 0:
            h=1
    else:
        h=-1
    t1, m1, h1 = 0, 0, 0

    if s1.count("T") == 2 * s1.count("M"):

        f1 = 0
        for i in range(len(s)):
            if s1[i] == "T":
                t1 += 1
            elif s1[i] == "M":
                m1 += 1
            # print(t,m)
            if m1> t1:
                h1 = -1
                f1=1
                break
        if f1 == 0:
            h1 = 1
    else:
        h1 = -1
    if h1 ==1 and h ==1:
        print("YES")
    else:
        print("NO")