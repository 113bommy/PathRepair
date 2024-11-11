t=int(input())
for _ in range(t):
    a,b,n=[int(x) for x in input().split()]
    c=0;
    while(True):
        c+=1
        if(a+b>n):
            break
        if(a>b):
            b+=a
        else:
            a+=b
        #c+=1
    print(c)