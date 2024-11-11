s = input()
if len(s) < 26:
    for i in range(26):
        c = chr(ord("a")+i)
        if c not in s:
            print(s+c)
            exit()
else:
    for i in reversed(range(1,26)):
        if s[i-1] < s[i]:
            s1 = s[0:i-1]
            for j in range(26):
                c = chr(ord("a")+j)
                if c > s[i-1] and c not in s1:
                    print(s1+c)
                    exit()
    print(-1)