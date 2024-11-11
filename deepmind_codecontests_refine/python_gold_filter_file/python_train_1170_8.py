for _ in range(int(input())):
    n,m,x,y=map(int,input().split())
    lis=[]
    for i in range(n):
        tmp = input()
        lis.append(tmp)
    cost=0
    for i in lis:
        if('..' in i):
            tcount = i.count('..')
            if(2*x<=y):
                cost+=2*x*tcount
            else:
                cost+=y*tcount
            i = i.replace('..','')
        if('.' in i):
            tcount = i.count('.')
            cost+=x*tcount
            i=i.replace('.','')
    print(cost)