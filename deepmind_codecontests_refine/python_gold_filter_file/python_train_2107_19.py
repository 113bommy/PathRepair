x=int(input())
for a in range(0,x):
    y=int(input())
    x1=input().split()
    d=[]
    l=1
    s=''
    if len(set(x1))==1:
        print(1)
        s='1 '*y
    elif y%2==0 or x1[-1]==x1[0]:
        print(2)
        s='1 2 '*int(y/2)
        if y%2==1:
            s+='1 '
    else:
        f=True
        for c in range(0,y):
            d.append(l)
            if c!=y-1:
                if not x1[c]==x1[c+1] or not f:
                    l=3-l
                elif f:
                    f=False
        #print(d)
        if not f:
            print(2)
        else:
            if d[-1]==d[0]:
                print(3)
                d[-1]=3
    for each in d:
        s+=str(each)+' '
    print(s[:-1])
