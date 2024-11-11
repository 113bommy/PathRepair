for _ in range(int(input())):
    n,k,x=map(int,input().split())
    t=[1]
    s=input()
    for y in s:
        if y=='*':
            t[-1]+=k
        else:
            if t[-1]!=1:t.append(1)
    if t[-1]==1: t.pop(-1)

    if x==1: print(s.replace('*',''))
    else:
        x-=1
        ans=[]
        for c in t[::-1]:
            ans.append(x%c)
            x//=c
        ref = ans[::-1]
        fans=[]
        p=False
        c=0
        for x in s:
            if x=='*':
                if p == False:
                    fans.append('b'*ref[c])
                    c+=1
                    p=True

            else: fans.append('a');p=False
        print(''.join(fans))