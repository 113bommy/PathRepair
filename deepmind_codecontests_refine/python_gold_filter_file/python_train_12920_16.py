low=""
for i in range(97,97+26,1):
    low+=chr(i)
up=""
for i in range(65,65+26):
    up+=chr(i)
dig=""
for i in range(48,49+9):
    dig+=chr(i)
#
r = input
n = int(r())
res=""
for i in range(n):
    rs = str(r())
    s = [x.strip() for x in rs]
    fl,ll,fu,lu,fd,ld = -1,-1,-1,-1,-1,-1
    cnt = 0
    res = ""
    for c in s:
        if(c in low):
            if(fl == -1):
                fl = cnt
                ll = cnt
            else:
                ll = cnt
        elif(c in up):
            if(fu == -1):
                fu = cnt
                lu = cnt
            else:
                lu = cnt
        if(c in dig):
            if(fd == -1):
                fd = cnt
                ld = cnt
            else:
                ld = cnt
        cnt+=1
    if(fl != -1 and fu !=-1 and fd !=-1):
        for i in s:
            res+=i
        print(res)
    else:
        if(fl == -1 and fu == -1):
            s[fd] ='a'
            s[fd+1]='A'
        elif(fu == -1 and fd == -1):
            s[fl] = 'A'
            s[fl+1] = '1'
        elif(fl == -1 and fd == -1):
            s[fu] = 'a'
            s[fu+1] = '1'
        elif(fl!=-1 and fu!=-1):
            if(fl != ll):
                s[fl] = '1'
            else:
                s[fu] = '1'
        elif(fu!=-1 and fd!=-1):
            if(fu != lu):
                s[fu] = 'a'
            else:
                s[fd] = 'a'
        elif(fl!=-1 and fd!=-1):
            if(fl != ll):
                s[fl] = 'A'
            else:
                s[fd] = 'A'
        for i in s:
            res+=i
        print(res)
