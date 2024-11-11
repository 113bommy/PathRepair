t=int(input())
while t:
    n=int(input())
    l=list(map(int,input().split()))
    lol=l[0]
    cou=0
    i=0
    res=[]
    while i<n-2:
        if(l[i]==l[i+1]):
            res.append(l[i])
            res.append(l[i])
            i+=2
        elif(l[i]==l[i+2]):
            res.append(l[i])
            res.append(l[i])
            i+=3
        elif(l[i+1]==l[i+2]):
            res.append(l[i+1])
            res.append(l[i+1])
            i+=3
    if(i==n-2):
        if(l[i]==l[i+1]):
            res.append(l[i])
            res.append(l[i])
    if(len(res)==0):
        print(1)
        print(0)

    else:
        print(len(res))
        print(*res)
    t-=1
                   