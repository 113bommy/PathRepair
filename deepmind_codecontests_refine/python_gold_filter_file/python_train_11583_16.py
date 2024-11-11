for _ in range(int(input())):
    n,k = map(int,input().split())
    t = input()
    x=0
    c=0
    f=0
    if '1' not in t:
        print( (n-1)//(k+1) + 1)
        continue
    fo,lo = t.index('1'), len(t) - 1 - t[::-1].index('1')
    for i in range(fo+1,lo+1):
        if t[i]=='0' and f==0:
            f=1
            c=1
        elif t[i]=='0' and f==1:
            c+=1
        else:
            f=0
            if c!=0:
                x+=((c-k)//(k+1))
    x+=fo//(k+1)
    x+=(n-1-lo)//(k+1)
    print(x)