s=sorted(list(map(int,input().split())))
if (s[0]+s[1])*2<=s[2]:
    print(s[0]+s[1])
else:
    print((s[0]+s[1]+s[2])//3)