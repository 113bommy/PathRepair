t = int(input())
for _ in range(t):
    s = input()
    b = 0
    f = False
    e = 0
    c=0
    for i in range(len(s)):
        if s[i] == '1':
            e = i
            if not f:
                f = True
                b = i
    if b == e:
        print(0)
    else:
        for i in range(b,e):
            if s[i] == '0':
                c +=1
        print(c)