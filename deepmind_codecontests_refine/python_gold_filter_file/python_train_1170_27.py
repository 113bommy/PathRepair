for _ in range(int(input())):
    n,m,p,o=list(map(int,input().split()))
    l=[]
    a=0
    b=0
    for i in range(n):
        s=input()
        b=b+s.count(".")
        l.append(s)
    if 2*p<=o:
        print(p*b)
    else:
        d=0
        for i in range(n):
            t=""
            for j in range(m):
                if (l[i][j]=="."):
                    if l[i][j]==t:
                        t=""
                        d=d+1
                        continue
                t=l[i][j]
        print(d*o+(b-2*d)*p)
                    
        