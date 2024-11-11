q=int(input())
for i in range(q):
    n=int(input())
    nn=n
    nnn=n
    res=0
    li=[0]*100
    mx=-1
    l=[]
    while nn:
        cou=0
        n=nn
        while n:
            n=n//3
            if(n):
                cou+=1
        li[cou]=1
        if(mx==-1):
            mx=cou
        a=3**cou
        l.append(cou)
        nn-=a
        #print(nn,a)
    #print(l)
    l.sort()
    j=0
    lol=0
    mxx=0
    #print(mx)
    for i in l:
        if(i>=mxx):
            if(li[i]!=2):
                li[i]=2
            elif(li[i]==2):
                j=i
                #print(i,"lol")
                while li[j]:
                    j+=1
                #print(j,"lol")
                #print(j,"lol")
                if(j>mx):
                    lol=1
                    mx=j
                    break
                else:
                    #print(j)
                    li[j]=2
                    if(j>mxx):
                        mxx=j
    su=0
    if(lol):
        #print("lol")
        print(3**j)
    else:
        for i in range(0,mx+1):
            if(li[i]==2 and i>=mxx):
                su+=3**(i)
        if(su==0):
            print(nnn)
        else:
            print(su)