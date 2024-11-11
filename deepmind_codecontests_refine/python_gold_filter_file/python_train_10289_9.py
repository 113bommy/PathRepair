s=input()
alp="".join([chr(i) for i in range(97,97+26)])
if len(s)<26:
    for i in alp:
        if i not in s:
            print(s+i)
            exit()
else:
    if s=="".join([chr(i) for i in range(97,97+26)][::-1]):
        print(-1)
        exit()
    else:
        for i in range(24,-1,-1):
            for j in range(25,i,-1):
                if s[i]<s[j]:
                    print(s[:i]+s[j])
                    exit()
