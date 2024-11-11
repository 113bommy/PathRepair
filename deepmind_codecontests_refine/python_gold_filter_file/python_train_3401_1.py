n=int(input())
a=list(map(int,input().split()))
f=set(a)
flag=0
ans=[]
li=max(a)
for i in a:
    d=1
    while(i+d<=li):
        x=i+d
        if(x in f):
            flag=1
            ans=[i,x]
            if(x+d in f):
                print(3)
                print(i,x,x+d)
                exit(0)
        d*=2
if(flag==1):
    print(2)
    print(*ans)
else:
    print(1)
    print(a[0])
    
