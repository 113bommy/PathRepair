t=int(input())
for you in range(t):
    n=int(input())
    l=[]
    for i in range(n):
        s=input()
        l.append(s)
    if(l[0][1]==l[1][0]):
        z=l[0][1]
        lo=[]
        if(l[-1][-2]==z):
            lo.append((n,n-1))
        if(l[-2][-1]==z):
            lo.append((n-1,n))
        print(len(lo))
        for i in lo:
            print(i[0],i[1])
        continue
    if(l[-1][-2]==l[-2][-1]):
        z=l[-1][-2]
        lo=[]
        if(l[0][1]==z):
            lo.append((1,2))
        if(l[1][0]==z):
            lo.append((2,1))
        print(len(lo))
        for i in lo:
            print(i[0],i[1])
        continue
    lo=[]
    if(l[0][1]=='0'):
        lo.append((1,2))
    if(l[1][0]=='0'):
        lo.append((2,1))
    if(l[-2][-1]=='1'):
        lo.append((n-1,n))
    if(l[-1][-2]=='1'):
        lo.append((n,n-1))
    print(len(lo))
    for i in lo:
        print(i[0],i[1])