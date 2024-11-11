from math import sqrt
t=int(input())
while t:
    n=int(input())
    nn=n
    nnn=n
    num=[]
    n=int(sqrt(n))+1
    cou=0
    if(nn%2==0):
        cou+=1
        num.append(2)
    while nn%2==0:
        nn=nn//2
    for i in range(3,n,2):
        if(cou==3):
            break
        if(nn%i==0):
            cou+=1
            num.append(i)
        while nn%i==0:
            nn=nn//i
    if(nn!=1):
        cou+=1
        num.append(nn)
    if(cou>=3):
        print("YES")
        print(num[0],num[1],nnn//(num[0]*num[1]))
    else:
        if(cou==1):
            a=num[0]
            b=num[0]*num[0]
            c=nnn//(a*b)
            if(a!=b and a!=c and c>b):
                print("YES")
                print(a,b,c)
            else:
                print("NO")
        else:
            a=num[0]
            b=num[1]
            c=nnn//(num[0]*num[1])
            if(c!=a and c!=b and c>1):
                print("YES")
                print(num[0],num[1],c)
            else:
                print("NO")
    t-=1

