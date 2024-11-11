seto = set(['a','b','c'])
for _ in range(int(input())):
    getlost = False
    s = list(input())
    size = len(s)
    if size == 1:
        if s[0] == '?':
            s[0] = 'a'
    if size == 2:
        if s[0]==s[1] and s[0]!='?':
            getlost = True
        elif s[0] == '?':
            if s[1] == '?':
                s[0] = 'a'
                s[1] = 'b'
            elif s[1] == 'a':
                s[0] = 'b'
            elif s[1] == 'b':
                s[0] = 'c'
            elif s[1] == 'c':
                s[0] = 'a'
        elif s[1] == '?':
            if s[0] == '?':
                s[1] = 'a'
                s[0] = 'b'
            elif s[0] == 'a':
                s[1] = 'b'
            elif s[0] == 'b':
                s[1] = 'c'
            elif s[0] == 'c':
                s[1] = 'a'
    else:
        if s[0]=='?':
            if s[1] != '?':
                setoo = seto - set([s[1]])
                s[0] = setoo.pop()
            else:
                s[0] = 'a'
        for i in range(1,size-1):
            if s[i] == '?':
                if s[i+1] == '?':
                    setoo = seto - set([s[i-1]])
                    if len(setoo):
                        s[i] = setoo.pop()
                    else:
                        getlost = True
                else:
                    setoo = seto - set([s[i-1],s[i+1]])
                    if len(setoo):
                        s[i] = setoo.pop()
                    else:
                        getlost = True
            else:
                if s[i-1] != '?':
                    if s[i] == s[i-1]:
                        getlost = True
                if s[i+1] != '?':
                    if s[i] == s[i+1]:
                        getlost = True
            if getlost:
                break
        if s[-1] == '?':
                setoo = seto - set([s[-2]])
                s[-1] = setoo.pop()
    if getlost:
        print(-1)
    else:
        print(*s,sep="")