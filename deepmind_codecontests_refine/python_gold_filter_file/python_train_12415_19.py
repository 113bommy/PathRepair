test = int(input())
for t in range(test):
    si = int(input())
    a = list(map(int,input().split()))
    f = [i==n for n,i in enumerate(a)]
    r=[]
    stop=0
    while False in f:
        #print(a)
        #print(f)
        sa = sorted(a)
        m=-1
        for i in sa:
            if i==m or i==m+1:
                m = i
            else:
                break
        m+=1
        #print(m)
        if(m==si):
            for n,i in enumerate(f):
                if not i:
                    a[n] = si
                    break
            r.append(n+1)
        else:
            a[m] = m
            f[m] = True
            r.append(m+1)
    #print(a)
    #print(f)
    print(len(r))
    print(" ".join(map(str,r)))
