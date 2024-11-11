n,t=map(int,input().split())
a=10**(n-1)
b=10**n-1
flag=False
#print(a,b)
if(n==1 and t<10):
    for i in range(1,10):
        if(i%t==0):
            #print(i)
            break
    print(i)
else:
    for i in range(a,b):
        if(i%t==0):
            flag=True
            break
    if(flag):
        print(i)
    else:
        print(-1)