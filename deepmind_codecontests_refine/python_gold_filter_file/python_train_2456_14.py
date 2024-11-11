n,m=map(int,input().split())
l=list(map(int,input().split()))
a=min(l)
c=0
flag=0
if n==1:
    print(0)
else:
    for i in l:
        if (i-a)%m==0:
            c=c+(i-a)//m
        else:
            flag=1
            break
    if flag==1:
        print(-1)
    else:
        print(c)
                