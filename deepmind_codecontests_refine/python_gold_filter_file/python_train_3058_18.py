def convert(n,x):
    t=str(n)
    f=False
    for i in range(0,10):
        if int(t+str(i))%x==0:
            n= int(t+str(i))
            f=True
            break
    if f==True:
        return n
    else:
        return -1
    
a,b,n=map(int,input().split())
x=convert(a,b)
if x==-1:
    print(-1)
else:
    print(str(x) +"0"*(n-1))