n,m=map(int,input().split())
c=0
cc=0
for i in range(n):
    if(c%2==0):
        s="#"*m
        print(s)
        c=1
    else:
        c=0
        if(cc==0):
            s="."*(m-1)+"#"
            print(s)
            cc=1
        else:
            s="#"+"."*(m-1)
            print(s)
            cc=0