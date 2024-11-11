from math import ceil
t=int(input())
for _ in range(t):
    a,p = map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    sm=0
    for i in l:
        sm+=i
    if sm<=p:
        print("0")
        continue
    if len(l)==1:
        if l[0]>p:
            print(l[0]-p)
        else:
            print("0")
        continue
    xypair=2+sm-p
    y=0
    lsm=0
    while(1):
        x=ceil((sm-p+l[0]*y-lsm)/(1+y))
        if x<0:
            x=0
        #print(x+y)
        if x+y<=xypair:
            xypair=x+y
        else:
            break
        y+=1
        lsm+=l[a-y]
        if y==a:
            break
    print(xypair)


