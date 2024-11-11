for _ in range(int(input())):
    s=input()
    for i in range(1,27,2):
        for j in range(27):
            a=[]
            for k in range(len(s)):
                if s[k].islower():a+=chr(((ord(s[k])-97)*i+j)%26+97)
                else:a+=s[k]
            a=''.join(a)
            if 'this' in a or 'that' in a:print(a);break