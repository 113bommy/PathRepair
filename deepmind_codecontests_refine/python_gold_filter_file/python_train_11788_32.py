for _ in range(int(input())):
    s=input()
    a=0
    b=0
    c=0
    for i in range(len(s)):
        if s[i]=='1':
            c=1
            b=b+a
            a=0
        if s[i]=='0' and c:
            a=a+1
    print(b)