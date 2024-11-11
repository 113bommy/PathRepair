s=input()
slen=len(s)-1
slen2=(len(s)-1)//2
iswitch=0
for i in range(slen2):
    if s[i]!=s[slen-i-1]:
        iswitch=1

if s[-1]=='1' or s[0]=='0':
    iswitch=1

if iswitch==1:
    print(-1)
else:
    if slen==1:
        print("1 1")
    elif slen==2:
        print("1 2")
        print("1 3")
    else:
        if True:
            henlist=[]
            mae=1
            jswitch=0
            for i in range(slen):
                now=i+2
                if jswitch==0:
                    if s[now-1]=='1':
                        for i in range(now-mae):
                            henlist.append([mae+i, now])
                        mae=now
                        if now>(len(s))//2:
                            jswitch=1
                    else:
                        pass
                else:
                    henlist.append([mae, now])
        for hl in henlist:
            print(hl[0], hl[1])