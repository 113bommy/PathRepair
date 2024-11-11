leng,wigh=map(int,input().split())
cnt=0
for i in range(leng):
    st,cnt='#',cnt+1
    for q in range(wigh-1):
        if cnt%4==0: st=st+'.'
        elif cnt%2==0: st='.'+st
        else: st='#'+st
    print(st)