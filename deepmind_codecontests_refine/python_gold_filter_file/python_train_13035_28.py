a=int(input())
r=0
d=list()
while r<a:
    k=0
    b=[int(b) for b in input().split()]
    #print('b = ',b)
    c=[int(c) for c in input().split()]
    #print('c = ',c)
    if b[1] not in c:
        k=0
    else:
        t=1
        while t<=min(max(b[1],b[0]-b[1]),1005):
            #print(t)
            if (b[1]+t) not in c and b[1]+t<b[0]+1:
                #print('fffffffffffffffff')
                k=k+1
                break
            elif (b[1]-t) not in c and b[1]-t>0:
                k=k+1
                break
            else:
                #print('3333333333333333333333333')
                k=k+1
            #print(b[1]+t)
            t=t+1
    d.append(k)
    #print(k)
    r=r+1
r=0
while r<a:
    print(d[r])
    r=r+1
