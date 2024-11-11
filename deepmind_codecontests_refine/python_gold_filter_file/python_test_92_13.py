for i in range(int(input())):
    s=input()
    a=0
    for i in range(len(s)-1):
        if s[i]=='a' and s[i+1]=='b':
            a+=1
        if s[i]=='b' and s[i+1]=='a':
            a-=1
    if a==0:
        print(s)
    else:
        if s[0]=='a':
            s='b'+s[1:]
        else:
            s='a'+s[1:]
        a=0
        for i in range(len(s)-1):
            if s[i]=='a' and s[i+1]=='b':
                    a+=1
            if s[i]=='b' and s[i+1]=='a':
                a-=1
        if a==0:
            print(s)
        else:
            if s[0]=='a':
                s='b'+s[1:]
            else:
                s='a'+s[1:]
            if s[-1]=='a':
                s=s[:-1]+'b'
            else:
                s=s[:-1]+'a'
            a=0
            for i in range(len(s)-1):
                if s[i]=='a' and s[i+1]=='b':
                        a+=1
                if s[i]=='b' and s[i+1]=='a':
                    a-=1
            if a==0:
                print(s)
            else:
                if s[0]=='a':
                    s='b'+s[1:]
                else:
                    s='a'+s[1:]
                print(s)